//Matthew Lin
//Project 3
#include<iostream>
#include<iomanip>
using namespace std;

class BST
{
public:
	BST()			//Constructor
	{
		for (int i = 0; i < 1024; i++)
		{
			Tree[i] = -1;
		}
		
	}

	void insert(int element)		
	{
		int next = 0;
		int index = 1;
		if (Tree[1] == -1)
		{
			Tree[1] = element;			//Set Root 
		}
		else
		{
			while (next != -1)			//Traverse to find appropriate location for insert
			{
				if (Tree[index] < element)			//Goes right if element > current index
				{
					index = index * 2 + 1;
					next = Tree[index];
					if (next == -1)
					{
						Tree[index] = element;
					} 
				}
				else if (Tree[index] > element)
				{
					index = index * 2;			//Goes left if element < current index
					next = Tree[index];
					if (next == -1)
					{
						Tree[index] = element;
					}
				}
				else
				{
					cout << "Duplicate element detected!" << endl;			//Exits function if a duplicate is found
					return;
				}
			}
		}
	}

	void Find_max()			//Finds maximum value
	{
		int now = 0;
		int next = 0;
		int index = 1;
		if (Tree[1] == -1)			//If no root is set, display error message
		{
			cout << "There is nothing in the Tree to Search!" << endl;
			return;
		}
		while (next != -1)			//Keeps manuvering right for max value
		{
			now = index;
			index = index * 2 + 1;
			next = Tree[index];
			if (next == -1)
			{
				cout << "Max Value is " << Tree[now] << endl;
			}
		}
	}

	void Find_min()			//Finds minimum value
	{
		int now = 0;
		int next = 0;
		int index = 1;
		if (Tree[1] == -1)			//If no root is set, display error message
		{
			cout << "There is nothing in the Tree to Search!" << endl;
			return;
		}
		while (next != -1)			//Keeps moving left for min value
		{
			now = index;
			index = index * 2;
			next = Tree[index];
			if (next == -1)
			{
				cout << "Min Value is " << Tree[now] << endl;
			}
		}
	}

	void Print_BST()			//Prints all items in array that is part of the tree
	{
		cout << setw(7) << "Index" << setw(9) << "Element" << endl;

		for (int i = 0; i < 1024; i++)
		{
			if (Tree[i] == -1)
			{

			}
			else
			{
				cout << setw(5) << i << setw(7) << Tree[i] << endl;
			}
		}

	}

	void Search(int element)			//Prints path of the element in the tree
	{
		int next = 0;
		int index = 1;
		if (Tree[1] == -1)			//If no root is set, display error message
		{
			cout << "There is nothing in the Tree to Search!" << endl;
			return;
		}
		else
		{
			cout << Tree[index] << "-";
			while (next != -1 && Tree[index] != element)			//Finds the element in the tree while leaving a trail
			{
				if (Tree[index] < element)			//Goes right if element > current index
				{
					index = index * 2 + 1;
					next = Tree[index];
					if (Tree[index] != element)
					{
						cout << Tree[index] << "-";
					}
					else
					{
						cout << Tree[index] << endl;
					}
				}
				else
				{
					index = index * 2;			//Goes left if element < current index
					next = Tree[index];
					if (Tree[index] != element)
					{
						cout << Tree[index] << "-";
					}
					else
					{
						cout << Tree[index] << endl;
					}
				}
			}
		}
	}

private:
	int Tree[1024];			//Creates a tree array that can store 10 elements
};



void main()
{
	BST *t1 = new BST();
	t1->insert(5);
	t1->insert(8);
	t1->insert(3);
	t1->insert(1);
	t1->insert(4);
	t1->insert(9);
	t1->insert(18);
	t1->insert(20);
	t1->insert(19);
	t1->insert(2);
	t1->Print_BST();
	t1->Find_max();
	t1->Find_min();
	t1->Search(3);
	t1->Search(18);
	t1->Search(19);
}