#pragma once
template <typename T>
class Stack
{
private:
	T *st;
	size_t size;
	int current;
public:
	Stack(int max)
	{
		size = max; //задаваемый размер стека
		st = new T[size];
		current = 0;  //фактический размер стека
	}
	~Stack(void)
	{
		delete[]st;
	}
	void push(T elem)
	{
		st[current] = elem;
		current++;
	}
	void pop() //достать последний элемент
	{
		st[current--];
	}
	T top() //возвращает верхний элемент стека
	{
		return st[current - 1];
	}
	void printStack()
	{
		for (int i = current - 1; i >= 0; i--)
			cout << i << ":  " << st[i] << endl;
	}
	bool empty()
	{
		return current == 0;
	}
	size_t getSize()
	{
		return size;
	}
};

template <typename T>
class arrStack
{
private:
	T **st;
	size_t size;
	int current; //данные о текущем элементе
	int *aSize; //размер хранящихся массивов
	int i, j; //счетчики
public:
	arrStack(int max)
	{
		size = max; //задаваемый размер стека
		aSize = new int[size]; //размеры массивов, хранящихся в стеке
		st = new T*[size];
		current = 0;  //фактический размер стека
	}
	void push(T* elem, int arrSize)
	{
		aSize[current] = arrSize;
		st[current] = new T[aSize[current]]; //массив заданного размера в стеке 
		for (i = 0; i < aSize[current]; i++)
			st[current][i] = elem[i];
		current++;
	}
	void printStack()
	{
		cout << "printStack" << endl;
		for (i = current - 1; i >= 0; i--)
		{
			cout << endl << i << "-й элемент:" << endl;
			for (j = 0; j < aSize[i]; j++)
				cout << "№  " << j << " : " << st[i][j] << " | ";
		}
	}

	~arrStack(void)
	{
		delete[]st;
	}
	void pop() //достать последний элемент
	{
		current--;
		for (i = 0; i < aSize[current]; i++)
		{
			st[current][i] = NULL;
		}
		aSize[current] = NULL;
	}

	bool empty()
	{
		return current == 0;
	}
	size_t getSize()
	{
		return size;
	}
};