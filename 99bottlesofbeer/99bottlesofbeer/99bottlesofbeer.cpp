#include <iostream>
#include <string>

using namespace std;

/**
 * Append " bottles" or " bottle" depending on the number input
 * If `bottleCount` === 0 then return " no more bottles"
 * @returns A string in this format: `<bottleCount> bottle(s)`
 */
string makeBottleStr(int bottleCount);

int main()
{
	// The base string where the numbers will be placed (@s will be replaced by the appropriate number + bottle word)
	string baseString = "@s of beer on the wall, @s of beer! Take one down pass it around... @s of beer on the wall!";

	// Initial amount of beers on the wall
	int beerCount = 99;

	for (int i = beerCount; i > 0; i--)
	{
		// Copy the baseString to a new string so we don't lose the @s positions
		string newString = baseString;

		// Replace the @s with the appropriate number and bottle word
		newString.replace(newString.find("@s"), 2, makeBottleStr(i));
		// newString is now "<i> of beer on the wall, @s of beer! Take one down pass it around... @s of beer on the wall!"

		newString.replace(newString.find("@s"), 2, makeBottleStr(i));
		// newString is now "<i> of beer on the wall, <i> of beer! Take one down pass it around... @s of beer on the wall!"

		newString.replace(newString.find("@s"), 2, makeBottleStr(i - 1));
		// newString is now "<i> of beer on the wall, <i> of beer! Take one down pass it around... <i - 1> of beer on the wall!"

		cout << newString << '\n';

		if (i == 1)
		{
			cout << "Congrats you drank all the beer. Now you're drunk.\n";
		}
	}
}

string makeBottleStr(int bottleCount)
{
	if (bottleCount == 0)
	{
		// There are no bottles => "no more bottles"
		return "no more bottles";
	}

	string append = " bottles";
	if (bottleCount == 1)
	{
		// There is only one bottle => "1 bottle"
		append = " bottle";
	}
	return to_string(bottleCount) + append;
}
