// Insertion Sort
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

	//Insertion sort
	void insertionSort()
	{
		for (int i = 1; i < a.size(); i++)
		{
			int j = i;
			int temp = a[i];
			// Loop from j to all the previous numbers.
			// Check if (the value - 1) is greater than temp.
			while ((j > 0) && a[j - 1] > temp)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = temp;
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

	//Insertion Sort
	algorithms.insertionSort();

	// Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;



	cin.ignore();

}
