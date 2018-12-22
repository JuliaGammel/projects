#pragma once
template <typename T>
class aQueue
{
private:
	T **queuePtr;
	size_t size;
	int current, begin, end; //данные об очереди
	int *aSize; //размер хранящихся массивов
	int i, j; //счетчики
public:
	aQueue(int max)
	{
		size = max; //задаваемый размер очереди
		aSize = new int[size]; //размеры массивов
		queuePtr = new T*[size];
		current = 0;  //фактический размер
		begin = 0; end = 0;
	}
	void push(T* elem, int arrSize)
	{
		aSize[current] = arrSize;
		queuePtr[current] = new T[aSize[current]]; //массив заданного размера 
		for (i = 0; i < aSize[current]; i++)
			queuePtr[current][i] = elem[i];
		current++;
	}

	void printqueuePtr()
	{
		cout << "printqueuePtr" << endl;
		for (i = 0; i < current - 1; i++)
		{
			cout << endl << i << "-й элемент:" << endl;
			for (j = 0; j < aSize[i]; j++)
				cout << "№  " << j << " : " << queuePtr[i][j] << " | ";
		}
	}

	~aQueue(void)
	{
		//delete[]queuePtr;
	}
	void pop() //достать последний элемент
	{
		for (int i = 0; i < current - 2; i++)
		{
			if ((aSize[i]) <= (aSize[i + 1]))
				memcpy(&queuePtr[i], &queuePtr[i + 1], sizeof(T)*(aSize[i])); //куда копируем, что копируем, размер
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