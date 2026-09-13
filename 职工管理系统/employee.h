#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

//普通职工文件

class Employee :public Worker
{
public:

	Employee(int id, string mname, int deptid);// {	}
	//这里写上{},错误
	//编译器认为你在这里完成了函数的定义，给了一个空主体
	//而在cpp里又有{this->....},导致重复定义
	
	//显示个人信息函数  纯虚函数
	virtual void showInfo();//在.h中只做声明
	
	//获取岗位名称
	virtual string getDeptName();
	
};