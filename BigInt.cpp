// BigInt.cpp
#include "BigInt.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

// default constructor (storage should be empty)
BigInt::BigInt()
{
	storage.push_back(0); // 0 by default
}

// int constructor
BigInt::BigInt(int n)
{
	if (n == 0) // if the number is 0 then just insert 0 only
	{
		storage.push_back('0');
	}
	while (n > 0) // while the number is not negative
	{
		char num = (n % 10) + '0'; // mod 10 to account for ascii values, add char 0 to fix
		storage.push_back(num);
		n = n / 10;
	}
	reverse(storage.begin(), storage.end()); // flip bc least significant bit is at the start
}

// string constructor
BigInt::BigInt(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		storage.push_back(char(s[i])); // add contents of string as characters in storage
	}
}

// copy constructor
BigInt::BigInt(const BigInt& other)
{
	storage = other.storage;
}

// print all values of the vector
void BigInt::print()
{
	vector<char>::iterator it; // declare iterator
	for (it = storage.begin(); it != storage.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

// converts BigInt to int to compare values
int BigInt::toInt()
{
	vector<char>::iterator it;
	vector<char> d1 = storage;
	string s = "";
	for (it = d1.begin(); it != d1.end(); it++)
	{
		s = s + *it;
	}
	int temp = stoi(s); //stoi is part of <string> and is used convert string to integer
	return temp;
}

ostream& operator<<(ostream& output, const BigInt& d)
{
	if (d.storage.size() > 12)
	{
		output << d.storage[0] << "."; // add decimal after first number
		for (int i = 1; i < 13; i++)
		{
			output << d.storage[i];
		}
		output << "e"; // add exponent
		int exponent = d.storage.size() - 1;
		output << exponent;
	}
	else
	{
		// if the size is < 12, just print normally
		for (int i = 0; i < d.storage.size(); i++)
		{
			output << d.storage[i];
		}
	}
	return output;
}

BigInt BigInt::operator+(const BigInt& other)
{
	vector<char> d1 = storage;
	vector<char> d2 = other.storage;
	vector<char> n;

	// first vector will always be larger or the same as the second
	// if it is larger -> throws vector subscript out of range error
	// fix: if the first is indeed larger, add 0s to the second so they all have the same amount of digits
	if (d1.size() > d2.size())
	{
		reverse(d2.begin(), d2.end());
		while (d2.size() < d1.size()) // while size is lower, add 0s until both are the same size in order to do the math
		{
			d2.push_back('0');
		}
		reverse(d2.begin(), d2.end());
	}

	for (int it = d1.size() - 1; it >= 0; it--) // iterate backwards -> 1234 starts at 4
	{
		int x = d1[it] - '0';
		int y = d2[it] - '0';
		int sum = x + y;

		if (sum > 9) // if sum becomes a double digit, apply carry
		{
			sum = sum - 10; // subtract 10 for carrying
			char num = sum + '0';
			n.push_back(num);
			if (it == 0) // if at end of loop, add 1 to the end
			{
				n.push_back('1');
			}
			else
			{
				d1[it - 1] = d1[it - 1] + 1; // add carry over
			}
		}
		else // single digit, just append
		{
			char num = sum + '0';
			n.push_back(num);
		}
	}

	// concert the final vector into a string and assign it as a BigInt
	reverse(n.begin(), n.end());
	vector<char>::iterator it;
	string temp = "";
	for (it = n.begin(); it != n.end(); it++)
	{
		temp = temp + *it;
	}
	BigInt B(temp);
	return B;
}

BigInt BigInt::operator-(const BigInt& other)
{
	vector<char> d1 = storage;
	vector<char> d2 = other.storage;
	vector<char> n;

	if (d1.size() > d2.size()) // add 0s to make up for differences in sizes
	{
		reverse(d2.begin(), d2.end());
		while (d2.size() < d1.size())
		{
			d2.push_back('0');
		}
		reverse(d2.begin(), d2.end());
	}

	for (int it = d1.size() - 1; it >= 0; it--)
	{
		int x = d1[it] - '0';
		int y = d2[it] - '0';
		int diff = x - y;
		if (diff < 0) // if the total difference is negative, need to borrow
		{
			diff = diff + 10; // add 10 for borrowed value
			char num = diff + '0';
			n.push_back(num);
			d1[it - 1] = d1[it - 1] - 1; // apply borrow
		}
		else // if difference total is normal, no borrowing needed
		{
			char num = diff + '0';
			n.push_back(num);
		}
	}

	reverse(n.begin(), n.end());
	vector<char>::iterator it;
	string temp = "";
	for (it = n.begin(); it != n.end(); it++)
	{
		temp = temp + *it;
	}
	BigInt B(temp);
	return B;
}

// operator++ to increment
void operator++(BigInt& d, int dummy)
{
	d = d + BigInt(1);
}

// operator<= for i <= BigInt(50)
bool BigInt::operator<=(BigInt d)
{
	if (toInt() <= d.toInt())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// operator< for map
bool operator<(BigInt c, BigInt d)
{
	if (c.toInt() < d.toInt())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// operator== for BigInt comparison with n == 0 or 1
bool BigInt::operator==(BigInt d)
{
	if (storage == d.storage)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// operator= for BigInt i = 0
BigInt BigInt::operator=(const BigInt& n)
{
	// similar to copy constructor
	storage = n.storage;
	return *this;
}