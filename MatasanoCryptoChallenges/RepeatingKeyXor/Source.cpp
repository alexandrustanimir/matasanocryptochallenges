#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
// input  : Burning 'em, if you ain't quick and nimble
// input  : I go crazy when I hear a cymbal
// key    : ICE
// output :0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
// output :a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f
string repeatKey(string key, int desiredLength)
{
	string result = key;
	for (int i = 0; i < key.length() && result.length() < desiredLength; i++)
	{
		result += key[i];
		if (i == key.length() - 1 && result.length() < desiredLength)
			i = -1;
	}
	return result;
}
string repeteatXor(string message, string key)
{
	string result = "";
	if (message.length() != key.length())
		throw("Invalid Usage");
	for (auto&c : message)
	{
		result += c ^ key.at(result.length());
	}
	return result;
}

int main()
{
	string message = "Burning 'em, if you ain't quick and nimble";
	string key = "ICE";
	cout << repeteatXor(message, repeatKey(key, message.length())).c_str() << "\n";
	message = "I go crazy when I hear a cymbal";
	cout << repeteatXor(message, repeatKey(key, message.length())).c_str() << "\n";
}