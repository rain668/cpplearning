#include "Manager.h"
#include "worker.h"
#include <iostream>
#include <string>
using namespace std;

Manager::Manager(int id, string mname, int deptid)
{
	this->m_Id = id;
	this->m_Name = mname;
	this->m_DeptId = deptid;

}

//显示个人信息函数  纯虚函数
void Manager::showInfo()
{
	cout << "职工编号： " << this->m_Id << "\t职工姓名： "
		<< this->m_Name << "\t岗位： " << this->getDeptName()
		<< "\t岗位职责：完成老板交代任务，并下发给员工" << endl;

}

//获取岗位名称
string Manager::getDeptName()
{
	return  string("经理");
}

