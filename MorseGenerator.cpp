// MorseGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;
string codeArray[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string generateCode(string s)
{
	string output = "";
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		int ind = c - 97;
		output += codeArray[ind] + " ";
	}
	return output;
}

void playCode(string code)
{

	int dit = 800;
	int dah = 800;
	int timeUnit = 50;
	cout << code << endl;
	for (int i = 0; i < code.length(); i++)
	{
		if (isspace(code[i]))
		{
			this_thread::sleep_for(chrono::milliseconds(3*timeUnit));
		}
		else
		{
			if(code[i] == '-')
				Beep(dah, 3 * timeUnit);
			else if (code[i] == '.')
				Beep(dit, 1 * timeUnit);
			this_thread::sleep_for(chrono::milliseconds(1 * timeUnit));
		}
	}
}

bool isValid(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
			return false;
	}
	return true;

}

string toLower(string s)
{
	string out = "";
	for (int i = 0; i < s.length(); i++)
	{
		out += tolower(s.at(i));
	}
	return out;
}

int main()
{
	while (true)
	{
		cout << "Enter the string to be encoded" << endl;
		string temp = "";
		string play = "";
		getline(cin, temp);
		temp = toLower(temp);
		if (isValid(temp))
		{
			temp = generateCode(temp);
			cout << temp << endl;
			cout << "Would you like to play the code? (Y/N)";
			getline(cin, play);
			play = toLower(play);
			if (play == "y")
			{
				cout << "TEMP IS " << temp << endl;
				playCode(temp);
			}
			else
				continue;
		}
		else
		{
			cout << "String contains invalid character";
		}
	}
}


