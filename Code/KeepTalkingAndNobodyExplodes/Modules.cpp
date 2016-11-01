#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <Windows.h>
#include "Modules.h"
using namespace std;
// bombproperty functions

void welcomeScreen()
{
	// displays the welcome screen with pauses
	cout << "Just remember:"; Sleep(2000); cout << " Keep Talking and Nobody Explodes ";
	Sleep(1000); cout << ". "; Sleep(1000); cout << ". "; Sleep(1000); cout << ". "; Sleep(1000);
	system("cls"); // clear screens
}
int bombProperties(char serialChar[],int serialNumb[])
{
	// randomizes the serial array and returns a random number for bomb color
	srand(time(NULL));
	int bombColor;
	// For Serial Characters
	for (int i = 0; i < 4; i++)
	{
		int x = rand(); // randomizes between capital and lower case letters
		if (x % 2 == 0)
			serialChar[i] = (65 + (rand() % 26)); // random uppercase letter
		else
			serialChar[i] = (97 + (rand() % 26)); // random lower case letter
	}
	// For Serial Numbers
	for (int i = 0; i < 4; i++)
	{
		serialNumb[i] = rand() % 10; // random numbers between 0-9
	}
	// For Bomb Color
	bombColor = rand() % 4 + 1; // 1 = Red, 2 = Blue, 3 = Green, 4 = Yellow
	return bombColor;
	
}
void callBombProperties(char serialChar[], int serialNumb[], int bombColor)
{
	// displays the information from bombproperties
	// switches between characters and numbers
	cout << "Serial Number: ";
	for (int i = 0; i < 4; i++)
	{
		cout << serialChar[i] << serialNumb[i];
	}
	cout << endl;
	// checks bomb number and cout the corresponding colors
	cout << "Bomb Color: ";
	switch (bombColor)
	{
	case 1:
		cout << "Red";
		break;
	case 2:
		cout << "Blue";
		break;
	case 3:
		cout << "Green";
		break;
	case 4:
		cout << "Yellow";
		break;
	}
	cout << endl;
}
void setcolor(unsigned short color)
{ // function to change text color
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
// ********** Memory Game **********
void randomizeArray(int array[])
{
	srand(time(NULL));
	for (int i = 0; i <= 4; i++) // sets array to 0
	{
		array[i] = 0;
	}
	array[0] = rand() % 4 + 1;
	for (int i = 1; i <= 4; i++) // randomizes array and checks if it has repeated integers
	{
		int randNumb;
		do
		{
			randNumb = rand() % 4 + 1;
		} while (randNumb == array[1] || randNumb == array[2] || randNumb == array[3] || randNumb == array[4]);
		array[i] = randNumb;
	}
}
 bool  numberMemory()
{
	int waitTime = 1000;
	// ***** Stage 1 *****
	cout << "On the Subject of Memory \n" << "Remember to input the button position, not the button number \n" << endl << endl;
	cout << "Stage 1 \n" << endl;
	int stage1[5];
	randomizeArray(stage1);
	int display = stage1[0];
	cout << "       " << display << endl;
	cout << "_______________" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout <<"|"<< stage1[i] << "| ";
	}
	cout << endl;
	int ans1 = 0;
	switch (display) // Game Check Stage 1
	{
	case 1: // press button in the second position
	{
		cin >> ans1;
		if (ans1 != 2)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 2: // press button in the second position
	{
		cin >> ans1;
		if (ans1 != 2)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 3: // press button in the third position
	{
		cin >> ans1;
		if (ans1 != 3)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 4: // press button in the fourth position
	{
		cin >> ans1;
		if (ans1 != 4)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	
	}
	break;
	}
	system("cls");
	// ***** Stage 2 *****
	cout << "On the Subject of Memory \n" << "Remember to input the button position, not the button number \n" << endl << endl;
	cout << "Stage 2 \n" << endl;
	int stage2[5];
	randomizeArray(stage2);
	display = stage2[0];
	cout << "       " << display << endl;
	cout << "_______________" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "|" << stage2[i] << "| ";
	}
	cout << endl;
	int ans2 = 0;
	switch (display) // Game Check Stage 2
	{
	case 1: // press the button labled "4"
	{
		cin >> ans2;
		if (stage2[ans2] != 4)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	

	}
	break;
	case 2: // press the button in the same position as you pressed in stage 1
	{
		cin >> ans2;
		if (ans2 != ans1)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	
	}
	break;
	case 3: // press the button in the first position
	{
		cin >> ans2;
		if (ans2 != 1)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	
	}
	break;
	case 4: // press the button in the same position as you pressed in stage 1
	{
		cin >> ans2;
		if (ans2 != ans1)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}

	}
	break;
	}
	system("cls");
	// ***** Stage 3 *****
	cout << "On the Subject of Memory \n" << "Remember to input the button position, not the button number \n" << endl << endl;
	cout << "Stage 3 \n" << endl;
	int stage3[5];
	randomizeArray(stage3);
	display = stage3[0];
	cout << "       " << display << endl;
	cout << "_______________" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "|" << stage3[i] << "| ";
	}
	cout << endl;
	int ans3 = 0;
	switch (display) // Game Check Stage 3
	{
	case 1: // press the button with the same label you pressed in stage 2
	{
		cin >> ans3;
		if (stage3[ans3] != stage2[ans2])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}

	}
	break;
	case 2: // press the button with the same label you pressed in stage 1
	{
		cin >> ans3;
		if (stage3[ans3] != stage1[ans1])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 3: // press the button in the third position
	{
		cin >> ans3;
		if (ans3 != 3)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 4: // press the button labeled "4"
	{
		cin >> ans3;
		if (stage3[ans3] != 4)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	}
	system("cls");

	// ***** Stage 4 *****
	cout << "On the Subject of Memory \n" << "Remember to input the button position, not the button number \n" << endl << endl;
	cout << "Stage 4 \n" << endl;
	int stage4[5];
	randomizeArray(stage4);
	display = stage4[0];
	cout << "       " << display << endl;
	cout << "_______________" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "|" << stage4[i] << "| ";
	}
	cout << endl;
	int ans4 = 0;
	switch (display) // Game Check Stage 3
	{
	case 1: // press the button in the same position as your pressed in stage 1
	{
		cin >> ans4;
		if (ans4 != ans1)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}

	}
	break;
	case 2: // press the button in the first position
	{
		cin >> ans4;
		if (ans4 != 1)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 3:// Press the button in the same position as you press in stage 2
	{
		cin >> ans4;
		if (ans4 != ans2)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 4: // Press the button in the same position as you press in stage 2
	{
		cin >> ans4;
		if (ans4 != ans2)
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	}
	system("cls");

	// ***** Stage 5 *****
	cout << "On the Subject of Memory \n" << "Remember to input the button position, not the button number \n" << endl << endl;
	cout << "Stage 5 \n" << endl;
	int stage5[5];
	randomizeArray(stage5);
	display = stage5[0];
	cout << "       " << display << endl;
	cout << "_______________" << endl;
	for (int i = 1; i <= 4; i++)
	{
		cout << "|" << stage5[i] << "| ";
	}
	cout << endl;
	int ans5 = 0;
	switch (display) // Game Check Stage 3
	{
	case 1: // press the button with the same label you pressed in stage 1
	{
		cin >> ans5;
		if (stage5[ans5] != stage1[ans1])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}

	}
	break;
	case 2: // press the button with the same label you pressed in stage 2
	{
		cin >> ans5;
		if (stage5[ans5] != stage2[ans2])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 3:// press the button with the same label you pressed in stage 3
	{
		cin >> ans5;
		if (stage5[ans5] != stage3[ans3])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	case 4: // press the button with the same label you pressed in stage 4
	{
		cin >> ans5;
		if (stage5[ans5] != stage4[ans4])
		{
			cout << "WRONG!!!";
			Sleep(waitTime);
			return 1;
		}
	}
	break;
	}
	system("cls");


	return 0;


}
// ********** Simon Says **********

void simonSaysDisplay(int randomArray[], int size)
{ // randomizes array with integers 1-4 to be displayed as colors
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		randomArray[i] = rand() % 4 + 1;
	}

}
void displayColors(int display)
{
	int interval = 700; // sets pause between displaying colors
	switch (display) // checks the array for integers 1-4
	{
	case 1: // Color Red
	{
		for (int i = 0; i <= 3; i++) // displays grids with corresponding quadrants
		{
			for (int i = 0; i <= 5; i++)
			{
				setcolor(12); cout << "0";
			}
			cout << endl;
		}
		Sleep(interval);
		system("cls");
		Sleep(interval);
	}
	break;
	case 2: // Color Blue
	{
		for (int i = 0; i <= 3; i++)
		{
			cout << " " << setw(6);
			for (int i = 0; i <= 5; i++)
			{

				setcolor(9); cout << "0";
			}
			cout << endl;
		}
		Sleep(interval);
		system("cls");
		Sleep(interval);
	}
	break;
	case 3: // Color Green
	{
		for (int i = 0; i <= 3; i++)
		{
			cout << endl;
		}
		for (int i = 0; i <= 3; i++)
		{
			for (int i = 0; i <= 5; i++)
			{
				setcolor(10); cout << "0";
			}
			cout << endl;
		}
		Sleep(interval);
		system("cls");
		Sleep(interval);
	}
	break;
	case 4: // Color Yellow
	{
		for (int i = 0; i <= 3; i++)
		{
			cout << endl;
		}
		for (int i = 0; i <= 3; i++)
		{
			cout << " " << setw(6);
			for (int i = 0; i <= 5; i++)
			{
				setcolor(14); cout << "0";
			}
			cout << endl;
		}
		Sleep(interval);
		system("cls");
		Sleep(interval);
	}
	break;
	}
}
void simonSaysWelcome()
{  // welcome screen displays grid with colors
	for (int i = 0; i <= 3; i++)
	{
		for (int i = 0; i <= 5; i++) // quadrant 2
		{
			setcolor(12); cout << "0";
		}
		for (int i = 0; i <= 5; i++) // quadrant 1
		{
			setcolor(9); cout << "0";
		}
		cout << endl;
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int i = 0; i <= 5; i++) // quadrant 3
		{
			setcolor(10); cout << "0";
		}
		for (int i = 0; i <= 5; i++) // quadrant 4
		{
			setcolor(14); cout << "0";
		}
		cout << endl;
	}
}
void getCompareArray(int compareArray[], int cases)
{ // red = 1; blue = 2; green = 3; yellow = 4;
	switch (cases) // assigns simond says corresponding numbers
	{
	case 0: //BRYG
	{
		compareArray[1] = 2;
		compareArray[2] = 1;
		compareArray[3] = 4;
		compareArray[4] = 3;
	} break;
	case 1: //YGBR
	{
		compareArray[1] = 4;
		compareArray[2] = 3;
		compareArray[3] = 2;
		compareArray[4] = 1;
	} break;
	case 2: //GRYB
	{
		compareArray[1] = 3;
		compareArray[2] = 1;
		compareArray[3] = 4;
		compareArray[4] = 2;
	} break;
	case 3: // BYGR
	{
		compareArray[1] = 2;
		compareArray[2] = 4;
		compareArray[3] = 3;
		compareArray[4] = 1;
	} break;
	case 4: // RBYG
	{
		compareArray[1] = 1;
		compareArray[2] = 2;
		compareArray[3] = 4;
		compareArray[4] = 3;
	} break;
	case 5: // YGBR
	{
		compareArray[1] = 4;
		compareArray[2] = 3;
		compareArray[3] = 2;
		compareArray[4] = 1;
	} break;
	}
}
bool simondSays(int strikes, char serialChar[])
{

	simonSaysWelcome(); // Display four quadrants of colors
	setcolor(15);
	cout << endl << "Do you remeber everything? (y)";
	char ansyn;
	cin >> ansyn;
	while (ansyn != 'y') // user input to continue to game
	{
		cout << "Not a valid answer!\n";
		cin >> ansyn;
	}
	// sets arrays to 0 by default
	int randomArray[6] = { 0,0,0,0,0,0 };
	int compareArray[5] = { 0,0,0,0,0 };
	system("cls");
	for (int i = 3; i <= 6; i++)
	{
		simonSaysDisplay(randomArray, i); // randomizes colors into array
		for (int i = 0; i < 6; i++)
		{
			displayColors(randomArray[i]);  // displays the colors excluding 0
		}
		setcolor(15); // default color
		cout << endl << "Please repeat Simon (r,b,g,y): \n";
		// sets a comparison array for the random array based on bomb's serial number and game strike count
		int vowel = 0;
		for (int i = 0; i < 6; i++) // if serial number has a vowel
		{
			if (serialChar[i] == 'a' || serialChar[i] == 'A' ||
				serialChar[i] == 'e' || serialChar[i] == 'E' ||
				serialChar[i] == 'i' || serialChar[i] == 'I' ||
				serialChar[i] == 'o' || serialChar[i] == 'O' ||
				serialChar[i] == 'u' || serialChar[i] == 'U' ||
				serialChar[i] == 'y' || serialChar[i] == 'Y') // check vowels
			{
				vowel = 1; // if there is a vowel in serial number, vowel = 1
			}
		}

		if (vowel == 1) // if serial has a vowel
		{
			switch (strikes)
			{
			case 0: // 0 strikes
			{
				getCompareArray(compareArray, 0);
			}
			break;
			case 1: // 1 strike
			{
				getCompareArray(compareArray, 1);
			}
			break;
			case 2: // 2 strikes
			{
				getCompareArray(compareArray, 2);
			}
			break;
			}
		}
		else // if serial does not have vowel
		{
			switch (strikes)
			{
			case 0: // 0 strikes
			{
				getCompareArray(compareArray, 3);
			}
			break;
			case 1: // 1 strike
			{
				getCompareArray(compareArray, 4);
			}
			break;
			case 2: // 2 strikes
			{
				getCompareArray(compareArray, 5);
			}
			break;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			if (randomArray[i] > 0)
			{
				char ans;
				cin >> ans;
				int ansN;
				if (ans == 'r') // changes char input to int 
					ansN = 1;
				else if (ans == 'b')
					ansN = 2;
				else if (ans == 'g')
					ansN = 3;
				else if (ans == 'y')
					ansN = 4;
				if (ansN != compareArray[randomArray[i]]) // compares the ans with the arrays
				{
					cout << "WRONG!!!";
					Sleep(2000);
					return 1;
				}
			}
		}
		system("cls");
	}
	

	return 0;
}
// ********** Wires *************
bool wireGame(int serialNumb [])
{
		srand(time(NULL)); // Lets the "wires" be randomized each run
		int ans;
		string wireColorDisplay;
		int wireArray[4];
		for (int i = 0; i < 4; i++)
		{
			wireArray[i] = rand() % 4 + 1;
		}
		int red = 0, blue = 0, white = 0, yellow = 0;
		for (int i = 0; i < 4; i++)
		{
			switch (wireArray[i])
			{
			case 1:
				setcolor(12); cout << "==================== \n"; // corresponding number: 1
				red++;
				break;
			case 2:
				setcolor(9); cout << "==================== \n"; // corresponding number: 2
				blue++;
				break;
			case 3:
				setcolor(15); cout << "==================== \n"; // corrresponding number: 3
				white++;
				break;
			case 4:
				setcolor(14); cout << "==================== \n"; // corresponding number: 4
				yellow++;
				break;
			}
		}
		setcolor(15);
		cout << "\n Correspond wire position with integers 1 to 4. ";
		//RED WIRE(S) ---- SERIAL
		int redIndex;
		for (int i = 0; i < 4; i++)
		{
			if (wireArray[i] = 1)
				redIndex = i; // Cut the last red decremented wire
		}

		if (red > 1 && serialNumb[4] % 2 != 0)
		{
			cin >> ans;
			if (ans == redIndex) // If more than one red wire, last serial number digit = odd
			{
				return 0; //Lets user move on
			}
			else
			{
				cout << "WRONG!";
				Sleep(2000);
				return 1; // Counts it as a strike
			}

		}
		// YELLOW WIRES ---- Otherwise1
		for (int i = 0; i < 4; i++) // If last wire is yellow and no red, cut first wire
		{
			if (wireArray[i] = 4 && wireArray[i] != 1)
			{
				cin >> ans;
				if (ans == 1) // 1 stands for position of wire ||| stands for the first wire
					return 0;

				else
				{
					cout << "WRONG!"; // Strike counter
					Sleep(2000);
					return 1;
				}
			}
		}

		for (int i = 0; i < 4; i++) // If there is a blue wire, cut the first wire
		{
			if (wireArray[i] = 2 && blue == 1)
			{
				cin >> ans;
				if (ans == 1) // 1 stands for position of wire ||| stands for the first wire
					return 0;

				else
				{
					cout << "WRONG!"; // Strike counter
					Sleep(2000);
					return 1;
				}
			}
		}

		for (int i = 0; i < 4; i++) // If last wire is yellow and no red, cut first wire
		{
			if (wireArray[i] = 4 && yellow > 1)
			{
				cin >> ans;
				if (ans == 4) // 4 stands for position of wire ||| stands for the last wire
					return 0;

				else
				{
					cout << "WRONG!"; // Strike
					Sleep(2000);
					return 1;
				}
			}

		}
		//OTHERWISE ------ LAST ORDER
		cin >> ans;
		if (ans == 2)
			return 0;
		else
		{
			cout << "WRONG!"; // Strike
			Sleep(2000);
			return 1;
		}
}
