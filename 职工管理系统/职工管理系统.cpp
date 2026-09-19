#include <iostream>
#include <string>
#include "workerManager.h"//职工管理系统
#include "worker.h"//职工类
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

void test()
{
	//测试代码：
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;
	worker = new Manager(2, "李世民", 2);
	worker->showInfo();
	delete worker;
	worker = new Boss(3, "李渊", 3);
	worker->showInfo();
	delete worker;
}
int main()
{
//test();

	workerManager wm ;//实例化管理对象
	int choice = 0;
	while(true)
	{ 
	wm.Show_Menu();
	cout << "请输入您的选项： " << endl;
	cin >> choice;
	switch (choice)
	{ 
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			wm.save();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
		{
			wm.Del_Emp();			
			break;
		}
		case 4:
			wm.Find_Emp();
			break;
		case 5:
			wm.Mod_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clear_File();
			break;
		default:break;
	}
	
	}
	
}