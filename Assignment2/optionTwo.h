
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
	Pseudorandom()
	{
		this->seed = 0;
		this->multiplier = 0;
		this->increment = 0;
		this->modulus = 0;
	}
	Pseudorandom(int initialSeed, int newMultiplier, int newIncrement, int newModulus)
	{
		this->seed = initialSeed;
		this->multiplier = newMultiplier;
		this->increment = newIncrement;
		this->modulus = newModulus;
	}

	void setSeed(int newSeed)
	{
		this->seed = newSeed;
	}

	void generateNextNumber()
	{
		this->seed = (this->multiplier * this->seed + this->increment) % this->modulus;
	}

	int returnNextNumber()
	{
		generateNextNumber();
		return this->seed;
	}

	double returnDividedNextNumber()
	{
		generateNextNumber();
		return this->seed / static_cast<double>(this->modulus);
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