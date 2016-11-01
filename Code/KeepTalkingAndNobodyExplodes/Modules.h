#pragma once
void welcomeScreen();
int bombProperties(char serialChar[], int serialNumb[]);

void callBombProperties(char serialChar[], int serialNumb[],int bombColor);
bool numberMemory();

void setcolor(unsigned short color);
void simonSaysDisplay(int randomArray[], int size);
void displayColors(int display);
void simonSaysWelcome();
void getCompareArray(int compareArray[], int cases);
bool simondSays(int strikes, char serialChar[]);

bool wireGame(int serialNumb []);
// creates bomb class and uses functions to denote serial number and color
class Bomb
{
public:
	char serialChar[4];
	int serialNumb[4];
	int bombColor = bombProperties(serialChar, serialNumb);

	void propertiesDisplay()
	{
		callBombProperties(serialChar, serialNumb, bombColor);
	}
};