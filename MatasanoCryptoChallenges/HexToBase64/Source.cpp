#include <string>
#include "base64.h"
#include <iostream>

using namespace std;

/* Hex to base 64
input  : 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
output : SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
*/
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
string asciiToString(string input)
{
	string res = "";
	for (int i = 0; i < input.length(); i = i + 2)
	{
		auto substr = input.substr(i, 2);
		cout << static_cast<char>(std::stoi(substr));
	}
	return res;
}

int main()
{

	string input = hexToAscii("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
	auto result = base64_encode(input.c_str(), input.length());

	cout << result;
}