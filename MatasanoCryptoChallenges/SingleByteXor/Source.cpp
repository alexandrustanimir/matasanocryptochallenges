#include <map>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// input :'	1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736'
// ouput : single char key


static map<char, double> LetterFrequencies = {
	{ 'a', 0.08167 }, { 'b', 0.01492 }, { 'c', 0.02782 }, { 'd', 0.04253 }, { 'e', 0.12702 },
	{ 'f', 0.02228 }, { 'g', 0.02015 }, { 'h', 0.06094 }, { 'i', 0.06966 }, { 'j', 0.00153 },
	{ 'k', 0.00772 }, { 'l', 0.04025 }, { 'm', 0.02406 }, { 'n', 0.06749 }, { 'o', 0.07507 },
	{ 'p', 0.01929 }, { 'q', 0.00095 }, { 'r', 0.05987 }, { 's', 0.06327 }, { 't', 0.09056 },
	{ 'u', 0.02758 }, { 'v', 0.00978 }, { 'w', 0.02360 }, { 'x', 0.00150 }, { 'y', 0.01974 },
	{ 'z', 0.00074 } };
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
double CalculateScore(string input)
{
	double result = 0.0;
	for (auto& c : input)
	{
		if (c < 32 || c > 122)
		{
			return 0.0;
		}
		if (LetterFrequencies.find(c) == LetterFrequencies.end())
			continue;
		result += LetterFrequencies.at(c);
	}
	return result;	
}
char bruteforceKey(string input)
{
	string asciiText = hexToAscii(input);
	int key = 0;
	double score = 0.0;
	string decrypted = "";
	char res = '\0';

	for (int i = 0; i < 255; i++)
	{
		string xoredAscii = "";
		for (auto&c : asciiText)
		{
			xoredAscii += (c ^ i);
		}
		if (CalculateScore(xoredAscii)> score)
		{
			score = CalculateScore(xoredAscii);
			decrypted = xoredAscii;
			key = i;
		}
	}
	cout << "Key :" << key << "\nString:" << decrypted.c_str() << "\nScore : " << score;
	return res;
}

int main()
{
	string input = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	cout << bruteforceKey(input);
}