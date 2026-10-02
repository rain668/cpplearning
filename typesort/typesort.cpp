// typesort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 利用函数模板封装一个排序的函数，要求该函数可以对任意类型的数组进行排序。
//排序规则为升序
//分别用char 数组和int 数组进行测试

#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[],int len)
{ 
	for (int i = 0;i < len-1;i++)
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1;j < len;j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (i != max)
		{
			mySwap(arr[i], arr[max]);
		}
		
	}
}

template <typename T>
void PrintArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test01()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, len);
	PrintArray(arr, len);
}

void test02()
{
	char arr[] = { 'a','b','c','d','e','f','g' };
	int len = sizeof(arr) / sizeof(arr[0]);
	mySort(arr, len);
	PrintArray(arr, len);
}


int main()
{
   
    test01();
	cout << endl;

    test02();
}

