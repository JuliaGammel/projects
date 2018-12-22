#pragma once
template <typename T>
class aQueue
{
private:
	T **queuePtr;
	size_t size;
	int current, begin, end; //������ �� �������
	int *aSize; //������ ���������� ��������
	int i, j; //��������
public:
	aQueue(int max)
	{
		size = max; //���������� ������ �������
		aSize = new int[size]; //������� ��������
		queuePtr = new T*[size];
		current = 0;  //����������� ������
		begin = 0; end = 0;
	}
	void push(T* elem, int arrSize)
	{
		aSize[current] = arrSize;
		queuePtr[current] = new T[aSize[current]]; //������ ��������� ������� 
		for (i = 0; i < aSize[current]; i++)
			queuePtr[current][i] = elem[i];
		current++;
	}

	void printqueuePtr()
	{
		cout << "printqueuePtr" << endl;
		for (i = 0; i < current - 1; i++)
		{
			cout << endl << i << "-� �������:" << endl;
			for (j = 0; j < aSize[i]; j++)
				cout << "�  " << j << " : " << queuePtr[i][j] << " | ";
		}
	}

	~aQueue(void)
	{
		//delete[]queuePtr;
	}
	void pop() //������� ��������� �������
	{
		for (int i = 0; i < current - 2; i++)
		{
			if ((aSize[i]) <= (aSize[i + 1]))
				memcpy(&queuePtr[i], &queuePtr[i + 1], sizeof(T)*(aSize[i])); //���� ��������, ��� ��������, ������
			if ((aSize[i]) >(aSize[i + 1]))
			{
				memcpy(&queuePtr[i], &queuePtr[i + 1], sizeof(T)*(aSize[i + 1]));
				aSize[i] = aSize[i + 1];
			}
		}
		current--;
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