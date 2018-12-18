#pragma once

using namespace std;

int abs(int);

int abs(int n)
{
	if (n > 0)
	{
		return n;
	}
	else
	{
		return n * (-1);
	}
}