#pragma once
#include "worker.h"
class Manager :    public Worker
{
public:	
	Manager(int id,string mname,int deptid);

	//显示个人信息函数  纯虚函数
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName() ;
};

