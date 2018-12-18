#include <iostream>
#include "string.h"
#include "staticArr.h"

using namespace std;

int quantity();
int inputNotation();
int inputAccuracy();
char inputCase();
double inputFraction();
void useSwitch();
void replaceStr(char*, int&, char*, int, char*, int);
void insertStr(char*, int, char*, int, int);
void notationConversion(double, int, int, char*);
void round(char*, int);
void replaceStr(char*, int&, char*, char*);
void deleteStr(char*, int, char*);
void deleteStr(char*, int, int);



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

int inputAccuracy()
{
	int accurecy;
	cout << "Input accurecy of tranformation" << endl;
	cin >> accurecy;
	system("cls");

	return accurecy;
}

double inputFraction()
{
	double fraction;
	cout << "Input fractional number" << endl;
	cin >> fraction;
	system("cls");

	return fraction;
}

int inputNotation()
{
	int notation;
	cout << "Input notation from binary to hexadecimal except decimal by inputting number from 2 to 16" << endl;

	while (true)
	{
		cin >> notation;
		system("cls");

		if (1 < notation && notation < 17 && notation != 10)
		{
			system("cls");
			return notation;
		}

		cout << "Wrong number. Try again" << endl;
	}
}

char inputCase()
{
	char letter;

	while (true)
	{
		cout << "choosing algorithm. you need to write algorithm title (letter after => )\nCut string to the array of words=> a\nConversion from decimal notation to other with given accuracy => b\nTo replace all appearances of the particular word in string => c\nTo delete all appearances of the particular word in string => d\ntitle: ";
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
		char str[N] = { 0 };
		char words[N][N] = { { 0 } };

		cout << "String:\n";
		int n = quantity();
		inputArr(n, str);

		wordsInStr(str, words);

		displayArr(words);
		break;
	}

	case 'b':
	{
		double number = inputFraction();
		int notation = inputNotation();
		int accuracy = inputAccuracy();
		char result[N] = { 0 };

		notationConversion(number, notation, accuracy, result);

		cout << "The result of transformation " << number << " in " << notation << " notation is ";
		displayArr(result);
		break;
	}

	case 'c':
	{
		const int N = 100;
		char target[N] = { 0 };
		char toSwap[N] = { 0 };
		char toChange[N] = { 0 };
		int n, m;

		while (true)
		{
			cout << "Target string:\n";
			n = quantity();
			cout << "String to be replaced:\n";
			m = quantity();
			system("cls");

			if (n < m)
			{
				cout << "Target string should be greater than replaced string\n";
			}
			else
			{
				cout << "Target string:\n";
				inputArr(n, target);
				cout << "String to be replaced:\n";
				inputArr(m, toSwap);
				break;
			}
		}

		cout << "String to be insert:\n";
		int k = quantity();
		system("cls");
		inputArr(k, toChange);
		system("cls");

		displayArr(target);
		replaceStr(target, n, toSwap, toChange);
		displayArr(target);

		break;
	}


	case 'd':
	{
		const int N = 100;
		char target[N] = { 0 };
		char toDel[N] = { 0 };
		char toChange[N] = { 0 };
		int n, m;

		while (true)
		{
			cout << "Target string:\n";
			n = quantity();
			cout << "String to be deleted:\n";
			m = quantity();
			system("cls");

			if (n < m)
			{
				cout << "Target string should be greater than replaced string\n";
			}
			else
			{
				cout << "Target string:\n";
				inputArr(n, target);
				cout << "String to be deleted:\n";
				inputArr(m, toDel);
				system("cls");
				break;
			}
		}

		displayArr(target);
		deleteStr(target, n, toDel);
		displayArr(target);

		break;
	}

	case 'e':
	{
		const int N = 100;
		char target[N] = { 0 };
		char toDel[N] = { 0 };
		char toChange[N] = { 0 };
		int n, m;

		while (true)
		{
			cout << "Target string:\n";
			n = quantity();
			cout << "Length of strings that'll be deleted:\n";
			m = quantity();
			system("cls");

			if (n < m)
			{
				cout << "Target string should be greater than replaced string\n";
			}
			else
			{
				cout << "Target string:\n";
				inputArr(n, target);
				system("cls");
				break;
			}
		}

		displayArr(target);
		deleteStr(target, n, m);
		displayArr(target);

		break;
	}

	default:
	{
		break;
	}
	}
}

void insertStr(char* target, char* toChange, int k, int wordPosition)
{
	for (int i = wordPosition; i < wordPosition + k; i++)
	{
		target[i] = toChange[i - wordPosition];
	}
}

void replaceStr(char* target, int& n, char* toSwap, char* toChange)
{
	int	m = getLength(toSwap),
		k = getLength(toChange);

	while (wordInStr(target, toSwap) != -1)
	{
		int wordPosition = wordInStr(target, toSwap);

		shift(target, n, wordPosition, m, k);
		insertStr(target, toChange, k, wordPosition);
	}
}

void deleteStr(char* target, int n, char* toDel)
{
	int	m = getLength(toDel);

	while (wordInStr(target, toDel) != -1)
	{
		int wordPosition = wordInStr(target, toDel);

		shift(target, n, wordPosition, m);
	}
}

void deleteStr(char* target, int n, int toDellLength)
{
	while (wordInStr(target, toDellLength) != -1)
	{
		int wordPosition = wordInStr(target, toDellLength);

		shift(target, n, wordPosition, toDellLength);
	}
}

void notationConversion(double number, int p, int accuracy, char* result)
{
	char symbols[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int integerPart = (int)number;
	int i = 0;

	while (integerPart >= 1)
	{
		integerPart /= 10;
		i++;
	}

	integerPart = (int)number;
	double fractionalPart = number - (int)number;

	int k = 0;
	
	if (!integerPart)
	{
		result[k] = '0';
		k++;
	}

	while (integerPart > 0)
	{
		result[k] = symbols[integerPart % p];
		integerPart /= p;
		k++;
	}

	swap(result);

	result[k] = ',';
	k++;
	int lastIndex = accuracy + k;

	while (k <= lastIndex)
	{
		fractionalPart *= p;
		result[k] = symbols[(int)fractionalPart % p];
		k++;
		while(fractionalPart >= p)
		{
			fractionalPart -= p;
		}
	}

	round(result, p);
}

void round(char* arr, int p)
{
	int originalLength = getLength(arr) - 1, // coma is odd symbol
		length = originalLength;

	while (true)
	{
		if (arr[length] == '0' || arr[length] == '\0')
		{
			arr[length] = '\0';
			length--;
			continue;
		}

		break;
	}

	if (originalLength > getLength(arr))
	{
		return ;
	}

	char symbols[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	if (arr[length] < symbols[p / 2])
	{
		arr[length] = '\0';
	}
	else
	{
		int i = 0;

		while (arr[length - (1 + i)] == symbols[p - 1])
		{
			arr[length - i] = '\0';
			i++;
		}

		arr[length - i] = '\0';
		arr[length - (1 + i)]++;
	}
}










