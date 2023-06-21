#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int extractIntegerFromString(const std::string& str) {
	int result = 0;
	int sign = 1;
	//size_t i = 0;



	// Extract digits
	for (int i=0; i < str.length(); i++) {

		// Check for sign
		if (str[i] == '-') {
			sign = -1;
			//i++;
		}

		//check for digit
		else if (str[i] >= '0' && str[i] <= '9') {
			result = result * 10 + (str[i] - '0');
		}

	}

	return result * sign;
}

int main()
{
	int currentRegisterValue = 1;
	int currentCycleNumber = 1;
	int n = 1;
	int outputInt = 0;
	int sumOfValues = 0;
	int cpuCycle = 0;
	int regAddVal = 0;

	// Create a text string for the file
	string myText;

	// Read from the text file
	ifstream MyReadFile("inputFile.txt");


	// Use a while loop with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {

		if (!myText.find("addx")) //if "addx {number}" is the instruction
		{
			++currentCycleNumber; ++currentCycleNumber;
			++n; ++n;
			regAddVal = extractIntegerFromString(myText);
			currentRegisterValue = currentRegisterValue + regAddVal;
		} 

		if (!myText.find("noop")) //if "noop" is the instruction
		{
			++currentCycleNumber;
			++n;
		}

		//n++;

		if (n == 20) {
			outputInt = currentCycleNumber * currentRegisterValue;
			//cout<<"currentCycleNumber = "<<currentCycleNumber<<"\tcurrentRegisterValue = "<<currentRegisterValue<<"\toutputInt=";
			cout << outputInt << "\n";
			sumOfValues += outputInt;
			n = 0;
		}


		regAddVal = 0;

	}


	cout << "Sum: " << sumOfValues<<"\n";

	// Close the file
	MyReadFile.close();
	return 0;
}



