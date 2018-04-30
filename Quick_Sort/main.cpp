// Quick Sort
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

		for (int i = 0; i < 10; i++)
			cout << a[i] << "\n";
		cout << endl;
	}
	// Return vector size
	int vecSize()
	{
		return a.size() - 1;
	}

	// Quick Sort
	void quickSort(int left, int right)
	{
		// Variable Declaration
		int i = left;
		int k = right;
		int temp;

		int pivot = a[(left + right) / 2]; // find pivot

		while (i <= k) {

			while (a[i] < pivot)
				i++;

			while (a[k] > pivot)
				k--;

			if (i <= k) {
				temp = a[i];
				a[i] = a[k];
				a[k] = temp;
				i++;
				k--;
			}
		};

		// Recursive function depending on orientation of pivot
		if (left < k)
			quickSort(left, k);

		if (i < right)
			quickSort(i, right);
	}
};
//Main Function
int main()
{
	Algorithms algorithms("numbers.txt");

	cout << "Before sort: " << endl;
	algorithms.printArray();

	// Start Timer
	double start = clock();

	//Quicksort begins
	algorithms.quickSort(0, algorithms.vecSize());

	// Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;

	cin.ignore();
}