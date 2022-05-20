// 99bottlesofbeer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// My first program

#include <iostream>
#include <string>

using namespace std;

// So fun C++ thing with organizing functions

// Now you can more conscicely document your code

//
string howManyBottles(int beerCount);

//
string howManyBottlesLeft(int beerCount);
// ^ This tells the compiler the function exists


int main()
{
	int beerint;
// Integer initalised, will be the backbone of the program
	beerint = 100;
	string BeerMany = " of beer on the wall ";
	string OfBeer = " of beer. take one down pass it around ";
	string OnTheWall = " of beer on the wall\n";
	string NoBeer = "Congrats you drank all the beer. now you're drunk.";
// Various strings that will be wrote dependant on how many beers are left

	for (int i = beerint; i > 0; i--)
	{
		cout << i << howManyBottles(i) << BeerMany << i << OfBeer << howManyBottlesLeft(i) << howManyBottles(i) << OnTheWall;		
		if (i == 1)
		{
			cout << NoBeer;
		}
	}
};
// This loop will be the basis for printing everything

string howManyBottles(int beerCount) {
	string bottle = " bottle";
	
	if (beerCount >= 1) {
		bottle = bottle + "s";
	}

	return bottle;
}
// This will check how many bottles are left and will amend an "s" for pluarlity 
string howManyBottlesLeft(int beercount) 
{
	if (beercount - 1 == 0 )
	{
		return "no";
	}
	return to_string(beercount - 1);
}
// This will check the number of beers left 
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu