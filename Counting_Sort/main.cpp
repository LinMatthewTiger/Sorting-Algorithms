// Counting Sort
#include <iostream>
#include <stdlib.h>
#include <array>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

class Algorithms {

private:
	vector<int> a;

public:
	//Constructor
	Algorithms(string fileName)
	{
		int temp = 0;
		srand(time(0));

		//Open the file and extract the data from it
		ifstream File(fileName);

		if (!File)
			cout << "**Error Reading File!**\n" << endl;
		else
		{
			cout << "Reading file..." << endl;
			while (File >> temp)
				a.push_back(temp);
			cout << "Done Reading File!" << endl;
		}
	}
	void printArray()
	{
		for (int i = 0; i < 11; i++)
			cout << a[i] << "\n";
		cout << endl;
	}

	//counting sort
	void countingSort()
	{
		int max = 0;			//Declare nessesary variables
		int size = a.size();

		for (int i = 0; i < a.size(); i++)		// Find maximum value to create an array that size
		{
			if (a[i] > max)
			{
				max = a[i];
			}
		}
		int* b = new int[max + 1];				// Dynamically allocate array of maximum value in list
		int* c = new int[a.size()];				// Create a new array to store the sorted list

		for (int i = 0; i < max + 1; i++)		// Initalize all elements in array b to 0
		{
			b[i] = 0;
		}

		for (int i = 0; i < a.size(); i++)		// Put each element in the list to it's respective index in array b
		{
			int index;
			index = a[i];
			b[index] += 1;
		}

		for (int i = 1; i < max + 1; i++)		// Add up preceeding elements in acending order
		{
			b[i] = b[i] + b[i - 1];
		}

		for (int i = a.size() - 1; i >= 0; i--) // Starting at the end of the list, find its respective index in array b and
		{										//   decrement the value at index b to find the proper index for the new sorted list
			int temp;
			int newindex;
			temp = a[i];

			b[temp] -= 1;
			newindex = b[temp];
			c[newindex] = temp;					// Store in array c
		}

		a.clear();								// Clear vector a

		for (int i = 0; i < size; i++) // Put sorted elements back into vector a
		{
			a.push_back(c[i]);
		}



	}
	
};
//Main Function
int main()
{
	int size = 10;
	Algorithms algorithms("numbers.txt");

	cout << "Before sort: " << endl;
	algorithms.printArray();

	// Start Timer
	double start = clock();

	//Sorting algorithms
	algorithms.countingSort();

	// Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;

	cin.ignore();

}