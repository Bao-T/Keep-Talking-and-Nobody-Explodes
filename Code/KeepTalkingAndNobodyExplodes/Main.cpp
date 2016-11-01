#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include "Modules.h"
using namespace std;

int main()
{
	srand(time(NULL));

	welcomeScreen();
	// calls and sets properties of the bomb.
	Bomb bombProperties;
	bombProperties.bombColor;
	bombProperties.serialChar;
	bombProperties.serialNumb;
	bombProperties.propertiesDisplay();


		//Difficulty Selector
		cout << "Please Choose Your Difficulty Level 1-10 (1 is easy, 10 is godly): ";
		int difficulty;
		cin >> difficulty;
		while (difficulty < 1 || difficulty > 10)
		{
			cout << "That is an invalid option. Please Choose Your Difficulty Level 1-6 (1 is easy, 6 is godly): ";
			cin >> difficulty;
		}
		system("cls");

		clock_t start = clock(); // Timer starts

		//randomizes games selection
		int gameRandomizer[10]; // overload to 10 for max selections
		for (int i = 0; i < 10; i++) // initializes all values to 0. if game reads 0 in array, case is skipped
		{
			gameRandomizer[i] = 0; // needed for when game finishes but 0 is left if array if difficulty was not 10
		}
		for (int i = 0; i < difficulty; i++) // assigns array value 1-6 for level of difficulty.
		{
			gameRandomizer[i] = rand() % 3 + 1; // %3 values 0-2, %3 +1 = vaues 1-3
		}
		
		int strikes = 0; // counts number of failures, terminates if reaches 3
		int i = 0; // sets first index of array for checking
		while (i < difficulty) // will continue to read games until difficulty level is matched, i will only increase if game is successful, if not, i stays the same to repeat the same game.
		{
			if (strikes < 3) // exits if strikes hits 3
			// Code for Game Selection
			{
				//switch (gameRandomizer[i]) // reads from array to determine which game will be played
					switch(0)
				{
				case 0:
				{
					i++; // skips to next index of array
				}
					break;
				case 1: // *****On The Subject Of Memory*****
				{
				
					bool x = numberMemory();
					if (x == 1)
						strikes++;
					else
						i++;
					system("cls");
				}
					break;
		
				case 2: // *****Simon Says*****
				{
					callBombProperties(bombProperties.serialChar, bombProperties.serialNumb, bombProperties.bombColor); // displays serial number and bomb color for game
					bool x = simondSays(strikes, bombProperties.serialChar);
					if (x == 1)
						strikes++;
					else
						i++;
					system("cls");
				}
				break;
				case 3: // ***** Wire Game *****
				{
					system("cls");
					callBombProperties(bombProperties.serialChar, bombProperties.serialNumb, bombProperties.bombColor); // displays serial number and bomb color for game
					bool x = wireGame(bombProperties.serialNumb);
					if (x == 1)
						strikes++;
					else
						i++;
					system("cls");
				}
				break;
				}
			}
			else if ( strikes == 3) // if strikes reaches 3 bomb explodes.
			{
				system("cls");
				cout << "BOOM! x_x \n";
				return 0; // exits here to avoid the issue of inifite loops when i never increases
			}
			{
				
			}
		}
		clock_t stop = clock(); // Timer Stops
		double elapsed = (double)(stop - start) / CLOCKS_PER_SEC; // calculates seconds
		system("cls");
		cout << "Congradulations you defused the bomb!!!!! \n";
		cout << "Time: " << elapsed << " seconds \n";
		return 0;// exits here to avoid the issue of inifite loops when i never increases
}