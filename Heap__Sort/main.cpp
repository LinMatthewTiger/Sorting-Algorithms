// Heap Sort
#include <iostream>
#include <stdlib.h>
#include <array>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

class Algorithms
{

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

		//Error Message
		if (!File)
			cout << "**Error Reading File!**\n" << endl;
		//Read the file
		else
		{
			cout << "Reading file..." << endl;
			while (File >> temp)
				a.push_back(temp);
			cout << "Done Reading File!" << endl;
		}
	}

	// To Print array
	void printArray()
	{
		for (int i = 0; i < 11; i++)
			cout << a[i] << "\n";
		cout << endl;
	}

	//Function to build maximum Heap Sort
	void maximum_heapify(vector<int> & a, int n, int i)
	{
		int maximum = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// Left > maximum
		if (left < n && a[left] > a[maximum])
			maximum = left;

		// Right > maximum
		if (right < n && a[right] > a[maximum])
			maximum = right;

		// maximum != i
		if (maximum != i)
		{
			int temp = 0;

			//Swaping
			temp = a[maximum];
			a[maximum] = a[i];
			a[i] = temp;

			// Recursively call the function again
			maximum_heapify(a, n, maximum);
		}
	}

	// Heap Sort
	void maxHeap()
	{
		// to build maximum heap
		for (int i = a.size() / 2 - 1; i >= 0; i--)
			maximum_heapify(a, a.size(), i);

		//Extract elements one at a time
		for (int i = a.size() - 1; i >= 0; i--)
		{
			//Swaping
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;

			// Recursively call maximum heapify
			maximum_heapify(a, i, 0);
		}
	}
};
//Main Function
int main()
{
	int size = 10;
	Algorithms algorithms("numbers.txt");

	cout << "Before sort: ";
	algorithms.printArray();

	// Start Timer
	double start = clock();

	//Heap Sort
	algorithms.maxHeap();

	// Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;



	cin.ignore();

}