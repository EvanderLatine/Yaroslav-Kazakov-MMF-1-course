#pragma once
#include <iostream>

using namespace std;

long long inputVeryLongNumber();
float inputAccuracy();
double inputArgument();
long double sqrt(double, float);
void outputResult(double);
long long factorial(long);
bool isPrimeNum(long long);
void quantityOfEachDigitInNumber(long long);
int fibonacciNumbers(int);
bool isPalindrome(long long);
long long createReverse(long long);


long long inputVeryLongNumber()
{
	long long num;
	cout << "What very long number do you want to use in calculations?\nnumber =  ";
	cin >> num;
	system("cls");
	return num;
}

float inputAccuracy()
{
	float accuracy;
	cout << "Setting accuracy\naccuracy = ";
	cin >> accuracy;
	system("cls");

	return accuracy;
}

double inputArgument()
{
	double arg;
	cout << "Setting real argument\nx = ";
	cin >> arg;
	system("cls");

	return arg;
}

long double sqrt(double number, float accuracy)
{
	double previousResult = 1, result = (previousResult + number / previousResult) / 2;

	while (abs(previousResult - result) > accuracy)
	{
		previousResult = result;
		result = (previousResult + number / previousResult) / 2;
	}

	return result;
}

void outputResult(double res)
{
	cout << "Result of calculating: " << res << endl;
}

long long factorial(long argument)
{
	long long factorial = 1;

	for (int i = 1; i <= argument; i++)
	{
		factorial *= i;
	}

	return factorial;
}

bool isPrimeNum(long long num)
{
	if (num <= 0)
	{
		return false;
	}
	bool result = true;

	for (long long i = 2; i < num; i++)
	{
		if (!(num % i))
		{
			result = false;
			break;
		}
	}

	return result;
}

void quantityOfEachDigitInNumber(long long number)
{
	cout << "Number is: " << number << endl;
	for (int i = 0; i < 10; i++)
	{
		long long j = 1, quantityOfDigit = 0;

		while (number / j)
		{
			long long quotient = number / j;
			if (quotient % 10 == i)
			{
				quantityOfDigit++;
			}
			j *= 10;
		}
		cout << "Quantity of digit " << i << " in number is " << quantityOfDigit << '\n';
	}
}

int fibonacciNumbers(int quantityOfDigits)
{
	int result = 2, addend = 1;

	while (!((int)(result / (pow(10, quantityOfDigits - 1)))))
	{
		int resultCopy = result;
		result += addend;
		addend = resultCopy;
		cout << result << "\t";
	}
	return result;
}

bool isPalindrome(long long number)
{
	return number == createReverse(number);
}

long long createReverse(long long number) {
	int sign = number >= 0 ? 1 : -1;
	number = abs(number);
	long long reverse = 0;

	while (number)
	{
		int digit = number % 10;
		reverse = reverse * 10 + digit;
		number /= 10;
	}

	return reverse * sign;
}