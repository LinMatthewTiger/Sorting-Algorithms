//Matthew Lin
//Project 1 
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

class LinkedList
{
public:
	LinkedList()
	{
		repeat[26];			//Used to check for repeats in indexes
		LList[26][2];		//Stack array
		MyTop = -1;			//Mytop declaration
		Counter = 0;		//Counter for items added to stack

	}
	void Empty()			//Check if stack is Empty or not
	{
		if (MyTop == -1)			//Only True when there is no data in the stack
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "The List is Empty!" << endl;
		}
		else
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "Thie List is NOT Empty!" << endl;
		}
	}
	void Push(int Value)
	{
		int index = 0;			//Holds the index of the stack
		if (Counter == 0)			//Only runs when the very first item is being put in the stack
		{
			index = rand() % 26;			//Random number generator
			repeat[Counter] = index;			//Puts index in an array to check for repeats
			LList[index][0] = Value;			//Puts data in stack
			LList[index][1] = MyTop;			//Puts MyTop in the "Next" portion of the stack
			MyTop = index;			//Changes Mytop to the new index to prepre for next data entry
			Counter += 1;			//Increment Counter to keep track of # of data input
		}
		else if (Counter == 26)			//Check if the stack is full
		{
			cout << "The List is FULL! Cannot add data! Use Pop() to remove data!" << endl;
			return;
		}
		else
		{
			index = rand() % 26;			//Random Number Generator
			repeat[Counter] = index;			//Puts index in the array to check for repeats
			for (int i = 0; i < Counter; i++)			//Check for repeats
			{
				if (repeat[i] == index)			//If there is a repeat, then make a new random number and reset "i"
				{
					index = rand() % 26;
					repeat[Counter] = index;
					i = -1;			//Resets i to check the stack again
				}
			}
			LList[index][0] = Value;			//Puts data in stack
			LList[index][1] = MyTop;			//Puts MyTop in the "Next" portion of the stack
			MyTop = index;			//Changes Mytop to the new index to prepare for next data entry
			Counter += 1;			//Increment Counter to keep track of # of data input
		}
	}
	void Top()			//Display MyTop's Data
	{
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(25) << "Data Removed:" << endl;
		cout << setw(10) << "Index" << setw(10) << "Value" << setw(10) << "Next" << endl;
		cout << setw(10) << MyTop << setw(10) << LList[MyTop][0] << setw(10) << LList[MyTop][1] << endl;
	}
	void Pop()
	{
		int Temp;
		if (MyTop == -1)			//Error message when trying to Pop() an empty stack
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "Error Removing Data! List is EMPTY!" << endl;
			return;
		}
		else
		{
			Temp = MyTop;			//Make new variable to avoid changing MyTop
			Counter -= 1;			//Decrement Counter to keep track of number of objects added to the stack
			MyTop = LList[MyTop][1];			//Shift MyTop to the "next" portion of the stack being removed
			LList[Temp][0] = -1;			//"Delete" the data in the stack
		}

	}
	void Display()			//Displays the data
	{
		int next = MyTop;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(25) << "Current List:" << endl;
		cout << setw(10) << "Index" << setw(10) << "Value" << setw(10) << "Next" << endl;
		do
		{
			cout << setw(10) << next << setw(10) << LList[next][0] << setw(10) << LList[next][1] << endl;
			next = LList[next][1];			//Shift to next item in stack
		} while (next != -1);			//Only false when it reaches the end of stack

	}
private:
	int repeat[26];			//Used to check for repeats in indexes
	int LList[26][2];		//Stack array
	int MyTop = -1;			//Mytop declaration
	int Counter = 0;		//Counter for items added to stack
};

int main() {
	srand(time(0));
	LinkedList a;

	a.Empty();
	a.Pop();
	a.Push(1);
	a.Display();
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Push(5);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	a.Push(9);
	a.Push(10);	
	a.Display();

	a.Push(20);
	a.Display();
	a.Push(30);
	a.Display();
	a.Push(40);
	a.Display();

	a.Top();
	a.Pop();
	a.Display();

	a.Top();
	a.Pop();
	a.Display();

	a.Top();
	a.Pop();
	a.Display();

	a.Empty();
	system("PAUSE");

	return 0;
}

