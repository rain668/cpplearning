#pragma once
#include "worker.h"
class Boss :    public Worker
{
public:	
	Boss(int id, string mname, int deptid);

	//显示个人信息函数  纯虚函数
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};

