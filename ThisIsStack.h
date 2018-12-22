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
		size = max; //���������� ������ �����
		st = new T[size];
		current = 0;  //����������� ������ �����
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
	void pop() //������� ��������� �������
	{
		st[current--];
	}
	T top() //���������� ������� ������� �����
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
	int current; //������ � ������� ��������
	int *aSize; //������ ���������� ��������
	int i, j; //��������
public:
	arrStack(int max)
	{
		size = max; //���������� ������ �����
		aSize = new int[size]; //������� ��������, ���������� � �����
		st = new T*[size];
		current = 0;  //����������� ������ �����
	}
	void push(T* elem, int arrSize)
	{
		aSize[current] = arrSize;
		st[current] = new T[aSize[current]]; //������ ��������� ������� � ����� 
		for (i = 0; i < aSize[current]; i++)
			st[current][i] = elem[i];
		current++;
	}
	void printStack()
	{
		cout << "printStack" << endl;
		for (i = current - 1; i >= 0; i--)
		{
			cout << endl << i << "-� �������:" << endl;
			for (j = 0; j < aSize[i]; j++)
				cout << "�  " << j << " : " << st[i][j] << " | ";
		}
	}

	~arrStack(void)
	{
		delete[]st;
	}
	void pop() //������� ��������� �������
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