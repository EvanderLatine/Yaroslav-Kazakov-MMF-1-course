#include <iostream>
#include "staticArr.h"

using namespace std;

int quantity();


char inputCase();
void useSwitch();
void outputResult(char);
void outputResult(int);
void replaceStr(char*, int&, char*, int, char*, int);
void insertStr(char*, int, char*, int, int);

int main()
{



	char esc = 'y';

	while (esc == 'y' || esc == 'y')
	{
		useSwitch();
		cout << "you can continue if you press y\n";
		cin >> esc;
		system("cls");
	}
	return 0;
}

int quantity()
{
	cout << "setting quantity of sequence numbers:\nnumber =  ";
	while (true)
	{
		int num;
		cin >> num;
		system("cls");

		if (num > 0)
		{
			return num;
		}

		cout << "quantity of sequence numbers should be greater than 0" << endl;
	}
}

char inputCase()
{
	char letter;

	while (true)
	{
		cout << "choosing algorithm. you need to write algorithm title (letter after => )\nCheck if strings are equal or not => a\nCompare strings => b\nFind first entrance of second string in first string => c\Find and replace word in string with another word => d\ntitle: ";
		cin >> letter;
		if (64 < letter && letter < 75 || 96 < letter && letter < 107)
		{
			system("cls");
			return tolower(letter);
		}

		system("cls");
	}
}

void useSwitch()
{
	switch (inputCase())
	{
	case 'a':
	{
		const int N = 100;
		char arr1[N] = { 0 };
		char arr2[N] = { 0 };
		
		cout << "First string:\n";
		int n = quantity();
		inputArr(n, arr1);
		
		cout << "Second string:\n";
		int m = quantity();
		inputArr(m, arr2);

		outputResult(equalStr(arr1, n, arr2, m));

		break;
	}

	case 'b':
	{
		const int N = 100;
		char arr1[N] = { 0 };
		char arr2[N] = { 0 };

		cout << "First string:\n";
		int n = quantity();
		inputArr(n, arr1);

		cout << "Second string:\n";
		int m = quantity();
		inputArr(m, arr2);

		outputResult(compareStr(arr1, n, arr2, m));

		break;
	}

	case 'c':
	{
		const int N = 100;
		char arr1[N] = { 0 };
		char arr2[N] = { 0 };
		int n, m;

		while (1)
		{
			cout << "First string:\n";
			n = quantity();
			inputArr(n, arr1);

			cout << "Second string:\n";
			m = quantity();
			system("cls");

			if (n < m)
			{
				cout << "Second string, that is searched for in first string should be less than first string\n";
			}
			else
			{
				inputArr(m, arr2);
				break;
			}
		}

		if (n < m)
		{
			
			break;
		}

		outputResult(wordInStr(arr1, n, arr2, m));

		break;
	}

	case 'd':
	{
		const int N = 100;
		char target[N] = { 0 };
		char toSwap[N] = { 0 };
		char toChange[N] = { 0 };
		int n, m;

		while (1)
		{
			cout << "Target string:\n";
			n = quantity();
			inputArr(n, target);

			cout << "String to be replaced:\n";
			m = quantity();
			system("cls");

			if (n < m)
			{
				cout << "Target string should be greater than replaced string\n";
			}
			else
			{
				inputArr(m, toSwap);
				break;
			}
		}

		cout << "String to be insert:\n";
		int k = quantity();
		inputArr(k, toChange);

		displayArr(target, n);
		replaceStr(target, n, toSwap, m, toChange, k);
		displayArr(target, n);
		break;
	}

	default:
	{
		break;
	}
	}
}

void outputResult(char result)
{
	cout << "array1 " << result << " array2" << endl;
}

void outputResult(int result)
{
	if (result == 1000)
	{
		cout << "Second strind doesn't appear in first string" << endl;
	}
	else
	{
		cout << "Second string starts from " << result + 1 << " symbol in first string" << endl;
	}
}

void insertStr(char* target, int n, char* toChange, int k, int wordPosition)
{
	for (int i = wordPosition; i < wordPosition + k; i++)
	{
		target[i] = toChange[i - wordPosition];
	}
}

void replaceStr(char* target, int& n, char* toSwap, int m, char* toChange, int k)
{
	while (wordInStr(target, n, toSwap, m) != 1000)
	{
		int wordPosition = wordInStr(target, n, toSwap, m);

		shift(target, n, wordPosition, m, k);
		insertStr(target, n, toChange, k, wordPosition);
	}
}

