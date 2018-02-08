/*
	Charles Cozart
	Custom Linked List
	CSC382
*/

#pragma once
#include <algorithm>

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
		DataNode(const T & inData = T{}, DataNode * next = nullptr, DataNode * prev = nullptr) : data{ indata }, nextitem{ next }, prevItem{ prevItem } {}

		//Constructor for rvalue reference objects, to allow for modification of objects in the linked list
		DataNode(T && inData, DataNode * next = nullptr, DataNode * prev = nullptr) : data{ std::move(indata) }, nextItem{ next }, prevItem{ prev } {}
	};	

public:
	//Empty Constructor creates empty linked list
	LinkedList();

	//Constructor to copy a const LinkedList into this list
	LinkedList(const LinkedList & inList);

	//Constuctor to copy a non-const LinkedList into this list
	LinkedList(LinkedList && inList);

	//Explicity destructor clears all items in the linked list, then deletes the head and tail pointers
	~LinkedList();

	//Insert method to insert a const value of type T into the list
	void Insert(const T & inData);

	//Insert method to insert a non-const value of type T into the list
	void Insert(T && inData);

	//Find method to find a const value of type T in the list
	T& Find(const T & inData) const;

	//Find method to find a non-sont value of type T in the list
	T* Find(T && inData);

	//Delete method to remove a const value of type T from the list
	void Delete(const T & inData);
	
	//Delete method to remove a non-const value of type T from the list
	void Delete(T && inData);

	const T & operator[](int x) const;

	T & operator[](int x);

	//Initalises all the values for an empty list
	void Init();

	//Deltes all data in the list
	void clear();

	//Returns the size of the list
	int Size() { return listSize; }

private:
	int listSize;
	DataNode *head;
	DataNode *tail;

};

