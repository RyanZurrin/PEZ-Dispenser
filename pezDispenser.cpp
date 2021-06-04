/**
 * @FileName pezDispenser.cpp
 * @Details build a pez dispenser simulator to test a stack ADT implementation
 * @Author Ryan Zurrin
 * @DateBuilt  2/24/2021
 * @DueDate 2/25/2021
 */
#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayFlavor(const int&);
const int MINRAND = 0;
const int MAXRAND = 7;

int main()
{
	Stack pez_dispenser(12);
	unsigned long long int seed = time(0);
	srand(seed);
	bool doneWithPEZ = false;
	int pick, flavor;
	int actions = 0;

	while (!doneWithPEZ)
	{
		if (actions % 7 == 0)
		{
			cout << "\n/============================================\\"<< endl;
			cout << "||          PEZ Dispenser Simulator         ||" << endl;
			cout << "|| ---------------------------------------- ||" << endl;
			cout << "||          1.)  Load PEZ dispenser         ||" << endl;
			cout << "||          2.)  Take a Candy               ||" << endl;
			cout << "||          3.)  Peek at Candy              ||" << endl;
			cout << "||          4.)  Dump all Candy             ||" << endl;
			cout << "||          5.)  Throw It Away              ||" << endl;
			cout << "\\============================================/" << endl;
		}
		cout << "\nEnter Menu Option\n>>";
		cin >> pick;
		if (pick >= 1 && pick <= 5)
		{
			switch (pick)
			{
			case 1:
				if (pez_dispenser.getQty()>0){
					std::cout << "Please use up or empty remaining candy"
							  << " before reloading";
					actions++;
					break;
				}
				while (!pez_dispenser.isFull())	{
					pez_dispenser.push(
						(rand() % (MAXRAND - MINRAND + 1)) + MINRAND);
				}
				std::cout << "the PEZ has been successfully loaded";
				actions++;
				break;
			case 2:
				pez_dispenser.pop(flavor);
				std::cout << "You have a ";	displayFlavor(flavor);
				actions++;
				break;
			case 3:
				pez_dispenser.peek(flavor);
				std::cout << "Next Flavor out is a ";	displayFlavor(flavor);
				actions++;
				break;
			case 4:
				std::cout << (pez_dispenser.getQty() != 0 ?
				 "throwing out all PEZ candies" : "no candy to throw out") << endl;
				pez_dispenser.makeEmpty();
				flavor = -1;
				actions++;
				break;
			case 5:
				pez_dispenser.makeEmpty();
				std::cout << "PEZ simulation now ending, Good Bye";
				doneWithPEZ = true;
				break;
			default:
				break;
			}
		}
		else {
			cout << "Invalid choice\n" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			actions++;
		}
	}
	return 0;
}//end main method

void displayFlavor(const int& val){
	switch (val){
	case 0:
		std::cout << "Cherry flavored PEZ candy." << std::endl;	break;
	case 1:
		std::cout << "Grape flavored PEZ candy." << std::endl; break;
	case 2:
		std::cout << "Lemon flavored PEZ candy." << std::endl; break;
	case 3:
		std::cout << "Orange flavored PEZ candy." << std::endl;	break;
	case 4:
		std::cout << "Raspberry flavored PEZ candy." << std::endl; break;
	case 5:
		std::cout << "Watermelon flavored PEZ candy." << std::endl;	break;
	case 6:
		std::cout << "Strawberry flavored PEZ candy." << std::endl;	break;
	case 7:
		std::cout << "Pineapple flavored PEZ candy." << std::endl; break;
	default:
		std::cout << "empty PEZ, please refill" << std::endl; break;
	}
}
