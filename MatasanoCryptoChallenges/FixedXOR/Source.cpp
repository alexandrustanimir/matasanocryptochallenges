#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// input :	   1c0111001f010100061a024b53535009181c
// XOR input : 686974207468652062756c6c277320657965
// output :    746865206b696420646f6e277420706c6179

unsigned char val(char c)
{
	if ('0' <= c && c <= '9') { return c - '0'; }
	if ('a' <= c && c <= 'f') { return c + 10 - 'a'; }
	if ('A' <= c && c <= 'F') { return c + 10 - 'A'; }
	throw "Eeek";
}

string hexToAscii(string input)
{
	string res = "";
	for (int i = 0; i < input.length(); i = i + 2)
	{
		auto substr = input.substr(i, 2);

		res += 16 * val((substr.at(0))) + val((substr.at(1)));
	}
	return res;
}
string XORStrings(string inputA, string inputB)
{
	if (inputA.length() != inputB.length())
		throw ("Invalid length");
	string a = hexToAscii(inputA);
	string b = hexToAscii(inputB);
	string result = "\0";
	for (int i = 0; i < a.length();i++)
	{
		result += a.at(i) ^ b.at(i);
	}
	for (auto& c : result)
	{
		cout << std::hex << (int)c;
	}
 	return result;
}


int main()
{
	string inputA = "1c0111001f010100061a024b53535009181c";
	string inputB = "686974207468652062756c6c277320657965";
	XORStrings(inputA, inputB);
	cout << "\n";

}