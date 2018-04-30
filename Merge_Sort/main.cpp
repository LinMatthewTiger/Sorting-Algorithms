// Merge Sort
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

	//Merge sort
	void mergeSort()
	{
		partition(0, a.size() - 1); // Function to partition and merge sort 
	}
	void merge(int startIndex, int endIndex)
	{
		int size = (endIndex - startIndex) + 1; // Find size of the area to be sorted
		int *b = new int[size]; // Dynamically allocate array for merge usage

		// Variable declarations
		int i = startIndex;
		int mid = (startIndex + endIndex) / 2;
		int k = 0;
		int j = mid + 1;

		// Compares the elements in array a and sort them in array b
		while (k < size)
		{
			if ((i <= mid) && (a[i] < a[j]))
			{
				b[k++] = a[i++];
			}
			else
			{
				b[k++] = a[j++];
			}

		}
		// Return values back into a
		for (k = 0; k < size; k++)
		{
			a[startIndex + k] = b[k];
		}

		delete[] b;		// Delete dynamically allocated array

	}

	//Partitions the array for sorting
	void partition(int startIndex, int endIndex)
	{
		int midIndex;

		//Check for base case
		if (startIndex >= endIndex)
		{
			return;
		}

		//Divide in half
		midIndex = (startIndex + endIndex) / 2;

		//Divide left side
		partition(startIndex, midIndex);
		//Divide right side
		partition(midIndex + 1, endIndex);
		//Activate merge function
		merge(startIndex, endIndex);

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

	//Merge Sort
	algorithms.mergeSort();

	// Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;



	cin.ignore();

}