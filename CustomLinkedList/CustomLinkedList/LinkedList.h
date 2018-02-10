/*
	Charles Cozart
	Custom Linked List
	CSC382
*/

#pragma once
#include <algorithm>
#include <exception>


template <typename T>
class LinkedList
{

private:
	struct DataNode
	{
		T data;
		DataNode *nextItem;
		DataNode *prevItem;

		//Constructor for const data objects
		DataNode(const T & inData = T{}, DataNode * next = nullptr, DataNode * prev = nullptr) : data{ inData }, nextItem{ next }, prevItem{ prevItem } {}

		//Constructor for rvalue reference objects, to allow for modification of objects in the linked list
		DataNode(T && inData, DataNode * next = nullptr, DataNode * prev = nullptr) : data{ std::move(inData) }, nextItem{ next }, prevItem{ prev } {}
	};

	//Nested class for custom exception to throw for index out of bounds
	class ArgumentOutOfRangeException : public exception
	{
		virtual const char* what() const throw()
		{
			return "Argument out of range";
		}
	} Argument_Out_Of_Range;

public:
	//Empty Constructor creates empty linked list
	LinkedList<T>()
	{
		Init();
	}

	//Constructor to copy a const LinkedList into this list
	LinkedList<T>(const LinkedList<T> & inList)
	{
		Init(); //Initializes an empty list

				//Loops through the list passed in, and inserts each item into the new list
		for (int i = 0; i < inList.listSize; i++)
		{
			Insert(inList.AtIndex(i));
		}
	}

	//Constuctor to copy a non-const LinkedList into this list
	LinkedList<T>(LinkedList<T> && inList)
	{
		Init(); //Initializes an empty list

				//Loops through the list passed in, and insterts each item into the new list
		for (int i = 0; i < inList.listSize; i++)
		{
			Insert(inList.AtIndex(i));
		}
	}

	//Explicity destructor clears all items in the linked list, then deletes the head and tail pointers
	~LinkedList<T>()
	{
		clear();
		delete head;
		delete tail;
	}

	//Insert method to insert a const value of type T into the list
	void Insert(const T & inData)
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
			newData->data = inData;

			head->nextItem->prevItem = newData;
			newData->nextItem = head->nextItem;
			newData->prevItem = head;
			head->nextItem = newData;

			listSize++;
		}
	}

	//Insert method to insert a non-const value of type T into the list
	void Insert(T && inData)
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

			head->nextItem->prevItem = newData;
			newData->nextItem = head->nextItem;
			newData->prevItem = head;
			head->nextItem = newData;

			listSize++;
		}
	}

	//Find method to find a const value of type T in the list
	T& Find(const T & inData) const
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

		return temp->data;
	}

	//Find method to find a non-sont value of type T in the list
	T* Find(T && inData)
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

		return temp->data;
	}

	 //boolean function returns true if the object is present in the list
	bool Contains(const T & inData)
	{
		bool result = false;

		DataNode *temp = head;
		if (listSize != 0)
		{
			temp = temp->nextItem;
			for (int i = 0; i < Size(); i++)
			{
				if (temp->data == inData)
				{
					result = true;
					break;
				}
				else
				{
					temp = temp->nextItem;
				}
			}
		}

		return result;

	}

	//boolean function returns true if the object is present in the list
	bool Contains(T && inData)
	{
		bool result = false;

		DataNode *temp = head;
		if (listSize != 0)
		{
			temp = temp->nextItem;
			for (int i = 0; i < Size(); i++)
			{
				if (temp->data == inData)
				{
					result = true;
					break;
				}
				else
				{
					temp = temp->nextItem;
				}
			}
		}

		return result;
	}

	//Delete method to remove a const value of type T from the list
	void Delete(const T & inData)
	{
		if (listSize == 0)
			return;
		else
		{
			DataNode *temp = head->nextItem;
			T tempData;
			for (int i = 0; i < listSize; i++)
			{
				tempData = temp->data;
				if (tempData == inData)
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
			listSize--;

		}
	}
	
	//Delete method to remove a non-const value of type T from the list
	void Delete(T && inData)
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
			listSize--;
		}
	}

	//Removes the item at the from of the list, used in the clear function
	void popFront()
	{
		if (Size() == 0)
			return;
		else
		{
			DataNode *temp = head->nextItem;

			head->nextItem = temp->nextItem;
			temp->nextItem->prevItem = head;

			delete temp;
			listSize--;
		}
	}

	//Returns the item of type T at the specified index of the list
	const T& AtIndex(int x) const
	{
		if (x > listSize)
			throw Argument_Out_Of_Range;
		else if (listSize == 0)
			throw Argument_Out_Of_Range;
		else
		{
			DataNode *temp = new DataNode();
			temp = head;
			T outData;
			for (int i = 0; i < listSize; i++)
			{
				temp = temp->nextItem;
				if (i == x)
				{
					outData = temp->data;
					break;
				}
			}

			return outData;
		}
	}

	//Returns the item of type T at the specified index of the list
	T& AtIndex(int x)
	{
		DataNode *temp = new DataNode();
		temp = head;
		if (x > listSize)
			throw Argument_Out_Of_Range;
		else if (listSize == 0)
			throw Argument_Out_Of_Range;
		else
		{
			for (int i = 0; i < listSize; i++)
			{
				temp = temp->nextItem;
				if (i == x)
				{
					break;
				}
			}

			return temp->data;
		}		
	}

	//Returns true if the list has 0 elements
	bool Empty()
	{
		return Size() == 0;
	}

	//Returns the size of the list
	int Size() { return listSize; }

private:
	//Initalises all the values for an empty list
	void Init()
	{
		head = new DataNode();
		tail = new DataNode();
		listSize = 0;
	}

	//Deltes all data in the list
	void clear()
	{
		while (!Empty())
		{
			popFront();
		}
	}


private:
	int listSize;
	DataNode *head;
	DataNode *tail;

};

