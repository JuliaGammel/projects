#pragma once 
#include "Node.h"
#include <exception>
#include <iostream>

using namespace std;



template<class T>
class Queue
{
private:
	Node<T> * top;
	size_t size;
public:
	Queue()
	{
		top = nullptr;
	}
	~Queue()
	{
		delete[]top;
	}
	void push(Node<T> * node)
	{
		if (top == nullptr)
			top = node;
		else
		{
			Node<T>* tmp = top;
			while (tmp->next != nullptr) //сдвигаем; tmp - промежуточная вершина, смотрит туда же куда и нод. в тим кладем, куда смотрит некст
			{
				tmp = tmp->next;
			}
			tmp->next = node;
		}
	}
	Node<T>* pop()
	{
		if (top == nullptr)
			throw 3;//std::out_of_range; 
		Node<T>* result = top;
		top = result->next;
		result->next = nullptr;
		return result;
	}
	bool empty()
	{
		return top == nullplr;
	}

	void clear()
	{
		while (top != nullptr)
		{
			Node<T>* current = top; //удалить один эл-т, открепить от очереди, очередь переставляем и удаляем
			top = top->next;
			delete current;
		}
	}
	size_t ssize() //считает кол-во элементов в очереди
	{
		size = 0;
		Node<T>* current = top;
		while (current != nullptr)
		{
			size++;
			current = current->next;

		}
		return size;
	}

};

/*Queue<int> queue;
for (int i = 0; i < rand() % 100; i++)
{
Node<int>* inode;
inode = new Node<int>();
inode->value = rand() % 1000;
queue.push(inode);
}*/