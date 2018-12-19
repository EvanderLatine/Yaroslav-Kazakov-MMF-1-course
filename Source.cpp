#include <iostream>

using namespace std;

void encoding(char[], int[], char[]);
void decoding(int[], char[], char[]);
void codingTests();
bool equals(char[], char[]);
int getLength(char*);
int getLength(int*);

int main()
{
	codingTests();
}

void encoding(char source[], int encoding[], char rule[])
{
	int length = getLength(source);

	for (int i = 0; i < length; i++)
	{
		int j = 0;

		while (source[i] != rule[j])
		{
			j++;
		}

		encoding[i] = j;
	}
}

void decoding(int source[], char decoding[], char rule[])
{
	int length = getLength(source);

	for (int i = 0; i < length; i++)
	{
		decoding[i] = rule[source[i]];
	}
}

bool equals(char lhs[], char rhs[])
{
	int i = 0;

	while (lhs[i])
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

void codingTests()
{
	const int length = 11;
	const int length1 = 28;
	const int ruleLength = 30;

	char source[length] = "learn c++!";

	int numbers[length] = { 0 };

	char rule[ruleLength] = "zyxwvutsrqponmlkjihgfedcba!+ ";

	encoding(source, numbers, rule);

	char expected[length];

	decoding(numbers, expected, rule);

	cout << equals(source, expected) << endl;

	// My custom test

	char source1[length1] = "I beleve it would be right!";

	int numbers1[length1] = { 0 };
	
	encoding(source1, numbers1, rule);

	char expected1[length1];

	decoding(numbers1, expected1, rule);

	cout << equals(source1, expected1) << endl;

}

int getLength(char* source)
{
	int length = 0;

	while (source[length]) // \ - escape sequence | source[length] != '\0' == source[length]
	{
		length++;
	}

	return length;
}

int getLength(int* source)
{
	int length = 0;

	while (source[length]) // \ - escape sequence | source[length] != '\0' == source[length]
	{
		length++;
	}

	return length;
}
