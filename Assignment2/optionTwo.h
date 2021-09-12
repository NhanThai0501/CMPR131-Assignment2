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
	Pseudorandom(int initialSeed, int newMultiplier, int newIncrement, int newModulus)
	{
		seed = initialSeed;
		multiplier = newMultiplier;
		increment = newIncrement;
		modulus = newModulus;
	}

	void changeSeed(int newSeed)
	{
		seed = newSeed;
	}

	int returnNextNumber()
	{
		int next;
		next = (multiplier * seed + increment) % modulus;
		seed = next;
		return next;
	}

	int getSeed() const
	{
		return  seed;
	}

	int getMultiplier() const
	{
		return  multiplier;
	}

	int getIncrement() const
	{
		return  increment;
	}

	int getModulus() const
	{
		return  modulus;
	}

	double returnDividedNextNumber()
	{
		return seed / static_cast<double>(modulus);
	}

};

// Additional functions
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