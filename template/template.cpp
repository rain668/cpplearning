// template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;



template<typename T>//声明一个模板
void mySwap(T &a,T &b) //引用方式传参
{
	T temp = a;
	a = b;
	b = temp;
}
void test()
{
	int a = 1;
	int b = 3;
	//1、自动类型推导模板函数
	mySwap(a, b);

	cout << "a: " << a << ", b: " << b << endl;
	double c = 1.1, d = 2.2;
	mySwap(c, d);
	cout << "c: " << c << ", d: " << d << endl;
	string e = "hello", f = "world";
	//2.显示指定类型的模板函数
	mySwap<string>	(e, f);
	cout << "e: " << e << ", f: " << f << endl;
}
int main()
{
    test();
}

