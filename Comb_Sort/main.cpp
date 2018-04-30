// Comb Sort
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

	// Comb sort
	void combSort()
	{
		int temp;							// Declare nessesary variables
		int gap = a.size();
		bool swapped = true;				// Utilized in case list is sorted early

		while (gap > 1 || swapped)			// If gap reaches 1 or the list is already sorted, stop the comb sort
		{
			if (gap > 1)					// Initalize the gap size
			{
				gap = gap / 1.3;			// 1.3 is the most efficent shrink factor
			}
			swapped = false;				// check if list is already sorted

			for (int i = 0; i + gap < a.size(); i++)  // Keep swapping with set gap size until the end of list is reached
			{
				if (a[i] > a[i + gap])		// Swap if comparing elements are in the wrong position
				{
					int temp = a[i];
					a[i] = a[i + gap];
					a[i + gap] = temp;
					swapped = true;			// Indicate a swap has been made meaning list in not sorted
				}
			}

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

	//Start Timer
	double start = clock();

	//Sorting algorithms
	algorithms.combSort();

	//Stop Timer
	double stop = clock();

	cout << "After sort: " << endl;
	algorithms.printArray();
	cout << "Time taken: " << (stop - start) / CLOCKS_PER_SEC << " seconds" << endl;

	cin.ignore();

}