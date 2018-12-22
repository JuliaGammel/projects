#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ThisIsStack.h"
#include "Queue.h"
#include "AnotherQuene.h"
using namespace std;

void full(int* arar, int size) //��������� �������� ������
{
	for (int j = 0; j < size; j++)
		arar[j] = rand() % 1000;
}




int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	arrStack <int> sInt(1000); //��� ����
	aQueue <int> qInt(1000);
	system("color a");
	clock_t start;	double duration; //��� �������� �������
	int size; //������� ��������
			  cout << "���� �� ������� ��������." << endl;
			  start = clock();
			  for (int j = 0; j < 1000; j++) //��� �������� �� int ��������
			  {
			  for (int i = 0; i < 1000; i++)
			  {
			  int *arr;
			  size = rand() % 100;
			  arr = new int[size];
			  full(arr, size);
			  sInt.push(arr, size);
			  delete[]arr;
			  }
			  for (int i = 0; i < 1000; i++)
			  sInt.pop();
			  }
			  duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			  cout << duration << endl; //�� ���� ~ 5 ��� 

	cout << "������� �� ������� ��������." << endl;
	start = clock();
	for (int j = 0; j < 991; j++) //��� �������� �� int ��������
	{
		//cout << "1 ";
		for (int i = 0; i < 990; i++)
		{
			int *arr;
			size = rand() % 100;
			arr = new int[size];
			full(arr, size);
			qInt.push(arr, size);
			delete[]arr;
		}
		for (int l = 0; l < 990; l++)
		{
			qInt.pop();
		}
	}
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	cout << duration << endl; //~ 10 ������
	

}

