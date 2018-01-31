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
		Node(const T & inData = T{}, Node * next = nullptr, Node * prev = nullptr) : data{ indata }, nextitem{ next }, prevItem{ prevItem } {}

		//Constructor for rvalue reference objects, to allow for modification of objects in the linked list
		Node(T && inData, Node * next = nullptr, Node * prev = nullptr) : data{ std::move(indata) }, nextItem{ next }, prevItem{ prev } {}
	};

	private:
		int listSize;
		DataNode *head;
		DataNode *tail;

};

