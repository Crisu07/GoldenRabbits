// BigInt.h
#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInt
{
private:
	vector<char> storage;
public:
	BigInt(); // default constructor
	BigInt(int n); // constructor for int value
	BigInt(string s); // constructor for string value
	BigInt(const BigInt& other); // copy constructor
	void print();
	friend ostream& operator<<(ostream& output, const BigInt& d);
	int toInt();
	BigInt operator+(const BigInt& other);
	BigInt operator-(const BigInt& other);
	friend void operator++(BigInt& d, int dummy); // postfix
	bool operator<=(BigInt d);
	friend bool operator<(BigInt c, BigInt d);
	bool operator==(BigInt d);
	BigInt operator=(const BigInt& n);
};
#endif
