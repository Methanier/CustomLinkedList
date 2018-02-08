#include "LinkedList.h"


//Default constructor for LinkedList
template <typename T>
LinkedList<T>::LinkedList()
{
	Init();
}

//Constructor that takes in a const LinkedList and creates a copy of the linked list
template <typename T>
LinkedList<T>::LinkedList(const LinkedList & inList)
{
	Init(); //Initializes an empty list

	//Loops through the list passed in, and inserts each item into the new list
	for (int i = 0; i < inList.listSize; i++)
	{
		Insert(inList[i]);
	}
}

//Constructor that takes in a non-const linkedList and creates a copy of the linked List
template <typename T>
LinkedList<T>::LinkedList(LinkedList && inList)
{
	Init(); //Initializes an empty list

	//Loops through the list passed in, and insterts each item into the new list
	for (int i = 0; i < inList.listSize; i++)
	{
		Insert(inList[i]);
	}
}

//Destructor for the linkedList
template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
	delete head;
	delete tail;
}

//Initializer function for the default constructor
template <typename T>
void LinkedList<T>::Init()
{
	head = nullptr;
	tail = nullptr;
	head->nextItem = tail;
	tail->prevItem = head;
	listSize = 0;
}
 //Deletes all data in the list
template <typename T>
void LinkedList<T>::clear()
{
	DataNode *tempOne = head->nextItem;
	DataNode *tempTwo = new DataNode();
	for (int i = 0; i < listSize; i++)
	{
		tempTwo = tempOne;
		tempOne = tempOne->nextItem;
		delete tempTwo;
	}
}

//Insert function for const data types. Inserts new data at the head of the linkedList
template <typename T>
void LinkedList<T>::Insert(const T & inData)
{
	DataNode newData = new DataNode();
	if (listSize == 0)
	{
		newData->data = inData;

		head->nextItem = newData;
		newData->prevItem = head;
		newData->nextItem = tail;
		tail->prevItem = newData;

		listSize++;
	}
	else
	{
		newData->Data = inData;

		newData->nextItem = head->nextItem;
		head->nextItem->prevItem = newData;
		newData->prevItem = head;
		
		listSize++;
	}
}


//Insert function for non-const data types. Inserts the data at the head of the linkedList
template <typename T>
void LinkedList<T>::Insert(T && inData)
{
	DataNode *newData = new DataNode();
	if (listSize == 0)
	{
		newData->data = inData;

		head->nextItem = newData;
		newData->prevItem = head;
		newData->nextItem = tail;
		tail->prevItem = newData;

		listSize++;
	}
	else
	{
		newData->Data = inData;

		newData->nextItem = head->nextItem;
		head->nextItem->prevItem = newData;
		newData->prevItem = head;

		listSize++;
	}
}

//Find function for const data types. Returns a reference to the object if it is found within the list
template <typename T>
T& LinkedList<T>::Find(const T & inData) const
{
	DataNode *temp = head;
	if (listSize != 0)
	{
		temp = temp->nextItem;
		for (int i = 0; i < listSize; i++)
		{
			if (temp->data == inData)
			{
				break;
			}
			else
			{
				temp = temp->nextItem;
			}
		}
	}

	return *temp->data;
}

//Find function for non-const data types. Returns a pointer to the object if it is found within the list
template <typename T>
T* LinkedList<T>::Find(T && inData)
{
	DataNode *temp = head;
	if (listSize != 0)
	{
		temp = temp->nextItem;
		for (int i = 0; i < listSize; i++)
		{
			if (temp->data == inData)
			{
				break;
			}
			else
			{
				temp = temp->nextItem;
			}
		}
	}

	return *temp->data;
}

//Delete function for const data types, removes the object if it is found within the list
template <typename T>
void LinkedList<T>::Delete(const T & inData)
{
	if (listSize == 0)
		return;
	else
	{
		DataNode *temp = head->nextItem;
		for (int i = 0; i < listSize; i++)
		{
			if (temp->data == inData)
			{
				break;
			}
			else
			{
				temp = temp->nextItem;
			}
		}

		
		temp->prevItem->nextItem = temp->nextItem;
		temp->nextItem->prevItem = temp->prevItem;

		delete temp;

	}
}

//Delete function for non-const data types, removes the object if it is found within the list
template <typename T>
void LinkedList<T>::Delete(T && inData)
{
	if (listSize == 0)
		return;
	else
	{
		DataNode *temp = head->nextItem;
		for (int i = 0; i < listSize; i++)
		{
			if (temp->data == inData)
			{
				break;
			}
			else
			{
				temp = temp->nextItem;
			}
		}


		temp->prevItem->nextItem = temp->nextItem;
		temp->nextItem->prevItem = temp->prevItem;

		delete temp;

	}
}

//Operator overload for the [] operator on const LinkedLists
template <typename T>
const T& LinkedList<T>::operator[](int x) const{

	if (x > listSize)
		return nullptr;
	else if (listSize == 0)
	{
		return nullptr;
	}
	else
	{
		DataNode *temp = head;
		for (int i = 1; i <; i++)
		{
			temp = temp->nextItem;
			if (i == x)
				return *temp;
			else
				return nullptr;
		}
	}
}

//Operator overload for the [] operator for non-const LinkedLists
template <typename T>
T& LinkedList<T>::operator[](int x)
{
	if (x > listSize)
		return nullptr;
	else if (listSize == 0)
		return nullptr;
	else
	{
		DataNode *temp = head;
		for (int i = 0; i <= x: i++)
		{
			temp = temp->nextItem;
			if (i == x)
				return *temp;
			else
				return nullptr;
		}
	}
}