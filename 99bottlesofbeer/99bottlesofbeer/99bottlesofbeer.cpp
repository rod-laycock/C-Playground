#include <iostream>
#include <string>

using namespace std;

/**
 * Append " bottles" or " bottle" depending on the number input
 * If `bottle_count` === 0 then return " no more bottles"
 * @returns A string in this format: `<bottle_count> bottle(s)`
 */
string make_bottle_str(int bottle_count);

int main()
{
	// The base string where the numbers will be placed (@s will be replaced by the appropriate number + bottle word)
	string base_string = "@s of beer on the wall, @s of beer! Take one down pass it around... @s of beer on the wall!";

	// Initial amount of beers on the wall
	int beer_count = 99;

	for (int i = beer_count; i > 0; i--)
	{
		// Copy the base_string to a new string so we don't lose the @s positions
		string new_string = base_string;

		// Replace the @s with the appropriate number and bottle word
		new_string.replace(new_string.find("@s"), 2, make_bottle_str(i));
		// new_string is now "<i> of beer on the wall, @s of beer! Take one down pass it around... @s of beer on the wall!"

		new_string.replace(new_string.find("@s"), 2, make_bottle_str(i));
		// new_string is now "<i> of beer on the wall, <i> of beer! Take one down pass it around... @s of beer on the wall!"

		new_string.replace(new_string.find("@s"), 2, make_bottle_str(i - 1));
		// new_string is now "<i> of beer on the wall, <i> of beer! Take one down pass it around... <i - 1> of beer on the wall!"

		cout << new_string << '\n';

		if (i == 1)
		{
			cout << "Congrats you drank all the beer. Now you're drunk.\n";
		}
	}
}

string make_bottle_str(int bottle_count)
{
	if (bottle_count == 0)
	{
		// There are no bottles => "no more bottles"
		return "no more bottles";
	}

	string append = " bottles";
	if (bottle_count == 1)
	{
		// There is only one bottle => "1 bottle"
		append = " bottle";
	}
	return to_string(bottle_count) + append;
}
