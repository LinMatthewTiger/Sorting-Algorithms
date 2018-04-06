//Matthew Lin
//Project 2 Bonus 
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
		LList[26][2];		//Queue array
		front = -1;			//Front and Back declaration
		back = -1;			
		Capacity = 0;		//Capacity for items added to queue

	}
	void Empty()			//Check if queue is Empty or not
	{
		if (front == -1)			//Only True when there is no data in the queue
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
	void Enqueue(int Value)
	{
		if (Capacity == 0)			//Only runs when the very first item is being put in the queue
		{
			index = rand() % 26;			//Random number generator
			repeat[Capacity] = index;			//Puts index in an array to check for repeats
			LList[index][0] = Value;			//Puts data in queue
			LList[index][1] = back;			//Puts back in the "Next" portion of the queue
			front = index;			//Assigns Front as first data entry
			temp = index;			//Changes temp to the new index to prepre for next data entry
			Capacity += 1;			//Increment Capacity to keep track of # of data input
		}
		else if (Capacity == 25)			//Check if the queue is full
		{
			cout << "The List is FULL! Cannot add data! Use Dequeue() to remove data!" << endl;
			return;
		}
		else
		{
			index = rand() % 26;			//Random Number Generator
			repeat[Capacity] = index;			//Puts index in the array to check for repeats
			for (int i = 0; i < Capacity; i++)			//Check for repeats
			{
				if (repeat[i] == index)			//If there is a repeat, then make a new random number and reset "i"
				{
					index = rand() % 26;
					repeat[Capacity] = index;
					i = -1;			//Resets i to check the queue again
				}
			}
			LList[temp][1] = index;			//Puts previous data's "Next" with new index  
			LList[index][0] = Value;			//Puts data in queue
			LList[index][1] = back;			//Puts back in the "Next" portion of the queue
			temp = index;		//Changes temp to the new index to prepare for next data entry
			Capacity += 1;			//Increment Capacity to keep track of # of data input
		}
	}
	void Front()			//Display Front's Data
	{
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(26) << "Data Removed:" << endl;
		cout << setw(10) << "Index" << setw(10) << "Value" << setw(10) << "Next" << endl;
		cout << setw(10) << front << setw(10) << LList[front][0] << setw(10) << LList[front][1] << endl;
	}
	void Dequeue()
	{
		int Temp2;
		if (front == -1)			//Error message when trying to Dequeue() an empty queue
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "Error Removing Data! List is EMPTY!" << endl;
			return;
		}
		else
		{
			Temp2 = front;			
			Capacity -= 1;			//Decrement Capacity to keep track of number of objects added to the queue
			front = LList[front][1];			//Shift front to the "next" portion of the queue being removed
			LList[Temp2][0] = -1;			//"Delete" the data in the queue
		}

	}
	void Display()			//Displays the data
	{
		int next = front;
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << setw(26) << "Current List:" << endl;
		cout << setw(10) << "Index" << setw(10) << "Value" << setw(10) << "Next" << endl;
		do
		{
			cout << setw(10) << next << setw(10) << LList[next][0] << setw(10) << LList[next][1] << endl;
			next = LList[next][1];			
		} while (next != back);			//Only false when it reaches the end of queue

	}
private:
	int index = 0;			//Used to store various indexes
	int repeat[26];			//Used to check for repeats in indexes
	int LList[26][2];		//queue array
	int front = -1;			//Front and Back declaration
	int back = -1;
	int Capacity = 0;		//Capacity for items added to queue
	int temp;			//Temporary term utilized to save previous data's index 
};

int main() {
	srand(time(0));
	LinkedList a;

	a.Empty();
	a.Dequeue();
	a.Enqueue(1);
	a.Display();
	a.Enqueue(2);
	a.Enqueue(3);
	a.Enqueue(4);
	a.Enqueue(5);
	a.Enqueue(6);
	a.Enqueue(7);
	a.Enqueue(8);
	a.Enqueue(9);
	a.Enqueue(10);
	a.Display();

	a.Enqueue(20);
	a.Display();
	a.Enqueue(30);
	a.Display();
	a.Enqueue(40);
	a.Display();

	a.Front();
	a.Dequeue();
	a.Display();

	a.Front();
	a.Dequeue();
	a.Display();

	a.Front();
	a.Dequeue();
	a.Display();

	a.Empty();
	system("PAUSE");

	return 0;
}