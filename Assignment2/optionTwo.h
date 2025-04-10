// optionTwo.h 

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include <math.h>
#include <vector>
// Functions Prototype
void displayArrayElements(vector<int> v);
int countElementsWithinRange(double begin, double end, vector<double> v);

// Class
class Pseudorandom
{
private:
	int seed = 0;
	int multiplier = 0;
	int increment = 0;
	int modulus = 0;

public:

	// Argument constructor
	Pseudorandom(int initialSeed, int newMultiplier, int newIncrement, int newModulus)
	{
		seed = initialSeed;
		multiplier = newMultiplier;
		increment = newIncrement;
		modulus = newModulus;
	}

	// Precondition: valid integer data
	// Postcondition: it will change the value of current "seed"
	void changeSeed(int newSeed)
	{
		seed = newSeed;
	}
	// Precondition: NA
	// Postcondition: return the next "seed" to replace the current "seed"
	int returnNextNumber()
	{
		int next;
		next = (multiplier * seed + increment) % modulus;
		seed = next;
		return next;
	}
	// Precondition: NA
	// Postcondition: return the value of "seed"
	int getSeed() const
	{
		return  seed;
	}
	// Precondition: NA
	// Postcondition: return the value of "multiplier"
	int getMultiplier() const
	{
		return  multiplier;
	}
	// Precondition: NA
	// Postcondition: return the value of "increment"
	int getIncrement() const
	{
		return  increment;
	}
	// Precondition: NA
	// Postcondition: return the value of "modulus"
	int getModulus() const
	{
		return  modulus;
	}
	// Precondition: NA
	// Postcondition: return the value of divided number after changing the "seed"
	double returnDividedNextNumber()
	{
		int next = returnNextNumber();
		return next / double(modulus);
	}

};

// Additional functions

// Precondition: valid vector that has integer type
// Postcondition: show the elements in the vector
void displayArrayElements(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i % 20 == 0)
			cout << "\n";
		if (i != v[v.size() - 1])
			cout << v[i] << ", ";
		else
			cout << v[i] << " ";

	}
}

// Precondition: valid initial range and end range, valid vector that has double type
// Postcondition: count the elements that appear within range
int countElementsWithinRange(double begin, double end, vector<double> v)
{
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= begin && v[i] < end)
		{
			count++;
		}
	}
	return count;
}

#endif
