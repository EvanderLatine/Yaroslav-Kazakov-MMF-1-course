#include <iostream>
#include "myLibrary.h"

using namespace std;


int inputDigit();
int inputNumber();

int useSwitch();




int main()
{
	char esc = 'y';

	while (esc == 'y' || esc == 'Y')
	{
		outputResult(useSwitch());
		cout << "You can continue if you press y\n";
		cin >> esc;
		system("cls");
	}
	return 0;
}



int inputNumber()
{
	int num;
	cout << "Setting integer:\nnumber =  ";
	cin >> num;
	system("cls");
	return num;
}

int inputDigit()
{
	int symbol;
	cout << "Setting symbol:\nsymbol =  ";
	cin >> symbol;
	system("cls");
	return symbol;
}



int useSwitch()
{
	switch (inputCase())
	{
		case 'a':
		{
			return quantityOfSymbol(decimalToBinary(inputNumber()), inputDigit());
			break;
		}

		default:
		{
			break;
		}
	}
}




