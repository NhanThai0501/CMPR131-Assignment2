// main.cpp

#include "menus.h"
#include "input.h"
#include "optionTwo.h"
#include <vector>

void mainMenu(void);
void programOne(void);
void programTwo(void);
int menuOption();

int main(void)
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        default: cout << "\tERROR-3A: Invalid input. Must be from 0..2."; break;
        }
        cout << endl;
        pause("Press Enter key to continue . . .");

    } while (true);
    return EXIT_SUCCESS;
}

int menuOption()
{
    //Input menu options
    clearScreen();
    cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Team" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << "\t\t1> List of Employees" << endl;
    cout << "\t\t2> Pseudorandom" << endl;
    cout << "\t" + string(85, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(85, char(205)) << endl;
    cout << endl;
    int userInput = inputInteger("\t\t Option: ", 0, 2);
    return userInput;
}
//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    clearScreen();
    displayMainMenu();
    int userInput = inputInteger("\t\tOption: ");
    do
    {
        switch (userInput)
        {
        case 0: clearScreen(); exit(1);  break;
        case 1: clearScreen(); programOne(); break;
        case 2: clearScreen(); programTwo(); break;
        default: cout << "\tERROR-3A: Invalid input. Must be from 0..2." << endl << endl; break;
        }
    } while (true);
}

void programOne(void)
{
    displayOptionOneMenu();

    do
    {
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': mainMenu(); break;
        case 'a': case 'A': /*function here*/; displayOptionOneMenu(); break;
        case 'b': case 'B': /*function here*/; displayOptionOneMenu(); break;
        case 'c': case 'C': /*function here*/; displayOptionOneMenu(); break;
        case 'd': case 'D': /*function here*/; displayOptionOneMenu(); break;
        case 'e': case 'E': /*function here*/; displayOptionOneMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E" << endl;
                 displayOptionOneMenu(); continue;
        }
    } while (true);
}

void programTwo(void)
{
	clearScreen();
	cout << "2> Pseudorandom Project" << endl;
	cout << string(100, char(196)) << endl;
	srand(time(0));
	const int SEED = 1;
	int multiplier = rand() % 1000 + 12000;
	int increment = rand() % 1000 + 12000;
	int modulus = rand() % 1000 + 12000;

	cout << "\t2> Pseudorandom Project" << endl;
	cout << "\ttest1 (pseudorandom): " << endl;
	cout << "\t\tSeed = " << SEED << endl;
	Pseudorandom object(SEED, multiplier, increment, modulus);

	vector<double> storeArray;

	//PART 2 OF THE PROGRAM
	for (int i = 0; i < 1000000; i++)
	{
		//cout << "Div num: #" << i + 1 << " = " << object.returnDividedNextNumber() << endl;
		storeArray.push_back(static_cast<double>(object.returnDividedNextNumber()));
	}
	sort(storeArray.begin(), storeArray.end());


	cout << "\t\tGenerated random 729 different numbers.\n" << endl;
	cout << "\ttest2 (pseudorandom): \n" << endl;

	cout << "\t\tmultiplier = " << multiplier << ", increment = " << increment << ", modulus = " << modulus << ", and the new seed = " << SEED << "\n" << endl;

	cout << "\t\tRange           Number of " << endl;
	cout << "\t\t                Occurrences" << endl;
	cout << "\t\t[0.0 ... 0.1)   " << countElementsWithinRange(0.0, 0.1, storeArray) << endl;
	cout << "\t\t[0.1 ... 0.2)   " << countElementsWithinRange(0.1, 0.2, storeArray) << endl;
	cout << "\t\t[0.2 ... 0.3)   " << countElementsWithinRange(0.2, 0.3, storeArray) << endl;
	cout << "\t\t[0.3 ... 0.4)   " << countElementsWithinRange(0.3, 0.4, storeArray) << endl;
	cout << "\t\t[0.4 ... 0.5)   " << countElementsWithinRange(0.4, 0.5, storeArray) << endl;
	cout << "\t\t[0.5 ... 0.6)   " << countElementsWithinRange(0.5, 0.6, storeArray) << endl;
	cout << "\t\t[0.6 ... 0.7)   " << countElementsWithinRange(0.6, 0.7, storeArray) << endl;
	cout << "\t\t[0.7 ... 0.8)   " << countElementsWithinRange(0.7, 0.8, storeArray) << endl;
	cout << "\t\t[0.8 ... 0.9)   " << countElementsWithinRange(0.8, 0.9, storeArray) << endl;
	cout << "\t\t[0.9 ... 1.0)   " << countElementsWithinRange(0.9, 1.0, storeArray) << endl;

}