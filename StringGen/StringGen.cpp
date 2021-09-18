// StringGen.cpp : Defines the entry point for the application.
//

#include "StringGen.h"

using namespace std;

#define TOLOWERCASE 32
#define TOCHARACTER 64

int random(int min, int max)
{
	return min + rand() % ((max + 1) - min);
}

bool check_range(int value, int min, int max) 
{
	return min <= value && value <= max;
}

void check_limits(int& max, char& current, int transform) {
	if (max > 0)
		max--;
	else
		current += transform;
}

std::string string_generator(const int size) 
{
	char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int maxUpperCaseLetters = random(1, 2);
	int maxNumCharaters = random(1, 2);

		
	string newString;
	srand((unsigned)time(NULL));
	
	int i = 0;

	while (i < size) 
	{
		char current = characters[random(0, sizeof(characters) -1)];
		
		if (check_range(current, 'A', 'Z'))
			check_limits(maxUpperCaseLetters, current, TOLOWERCASE);

		
		if (check_range(current, '0', '9')) 
			check_limits(maxNumCharaters, current, TOCHARACTER);

		newString += current;
		i++;

		if (i == size && (maxUpperCaseLetters + maxNumCharaters) > 0) 
		{
			newString = "";
			i = 0;
			maxUpperCaseLetters = random(1, 2);
			maxNumCharaters = random(1, 2);
		}
	}
	
	return newString;
}

int main()
{
	std::string result = string_generator(12);
	cout << result << endl;

	return 0;
}
