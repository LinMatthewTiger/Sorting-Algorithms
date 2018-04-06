//Matthew Lin
//Project 1 
#include<iostream>
using namespace std;



class node
{
public:
	int data;
	node *next;
};

class PointerList
{
public:
	PointerList()
	{
		top = NULL;
	}

	bool empty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void insert(int preptr_value, int element)
	{
		node *newptr = new node;
		newptr->data = element;
		bool insert = false;
		int position = 0;

		if (top == NULL)			//insert the very first element
		{
			newptr->next = NULL;
			top = newptr;
			position += 1;
		}
		else
		{
			node* temp;
			temp = top;	//Assign top to temp 
			while (temp != NULL && insert == 0) //Traverse through list to find matches
			{
				if (temp->data == preptr_value) //Indicate program to insert data once match is found
				{
					insert = true;
				}
				position += 1;	//Keep track of position to reuse insert code
				temp = temp->next;	//Shifts the temp to the next item
			}
			if (insert == true)				//Insert data
			{
				node *preptr;
				preptr = top;

				for (int i = 0; i < position - 1; i++)
					preptr = preptr->next;

				newptr->next = preptr->next;
				preptr->next = newptr;
			}
			else
			{
				cout << "Error inserting data. Data was not found" << endl;	//Error message if data was not found

			}

		}
	}

	void remove(int preptr_value)
	{
		bool remove = false;
		int position = 0;
		node* temp;
		temp = top;
		while (temp != NULL && remove == 0)	//Traverse list to find matches
		{
			if (temp->data == preptr_value)	//Indicate program to remove data once match is found
			{
				remove = true;
			}
			position += 1;
			temp = temp->next;
		}

		if (remove == true)	//Removes data after indicated value
		{
			node *preptr;
			preptr = top;
			for (int i = 0; i<position - 1; i++)
				preptr = preptr->next;

			node * ptr = preptr->next;
			preptr->next = ptr->next;
			delete(ptr);
		}
		else
		{
			cout << "Error removing data. Data not found";	//Error message if data was not found
			cout << endl;
		}

	}


	void print()
	{
		node *temp;
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
	}

private:
	node * top;
	int stackData;
};

int main() {
	PointerList *sl = new PointerList();
	int array[2];
	cout << array[0] << endl;
	system("PAUSE");
	sl->insert(0, 10); //current linked list: 10 (default status, when empty) 
	sl->insert(10, 20);	//current linked list: 10->20
	sl->print();
	cout << endl;
	sl->insert(20, 30);	//current linked list: 10->20->30
	sl->insert(20, 40);	//current linked list: 10->20->40->30
	sl->insert(30, 50);	//current linked list: 10->20->40->30->50
	sl->print();
	cout << endl;
	sl->insert(50, 60);	//current linked list: 10->20->40->30->50->60
	sl->insert(5, 70);	//error, no 5 existed in the linked list
	sl->print();
	cout << endl;
	sl->remove(30); 	//current linked list: 10->20->40->30->60
	sl->print();
	cout << endl;
	sl->remove(10);	//current linked list: 10->40->30->60
	sl->print();
	cout << endl;
	sl->remove(50);	//error, no 50 existed in the linked list
	sl->print();
	cout << endl;
	system("PAUSE");	//I added this because my visual studios won't display results unless I pause it. Can you tell me how to fix this?
	return 0;
}
