#include "workerManager.h"
#include <iostream>
#include <string>
#include "worker.h"
#include "employee.h"
#include "Boss.h"
#include "Manager.h"
#include <cassert>   // C++ 推荐写法
using namespace std;

workerManager::workerManager()
{
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		//初始化人数和数组
		this->m_EmpNum = 0;    //this指针表示 workerManager类
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//如何判断文件存在，并且没有记录
	char ch;
	ifs >> ch;//读文件流中的一个字符
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		//初始化人数和数组
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;//初始化文件是否为空
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	//当文件存在，记录数据
	int num = this->get_EmpNum();

	cout<< "职工人数为： " << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [num];//new 一个Worker 型指针数组
	this->init_Emp();

	/*测试代码
	for (int i = 0;i < num;i++)
	{
		cout<<"职工编号: "<<this->m_EmpArray[i]->m_Id;
		cout<< "  姓名: " << this->m_EmpArray[i]->m_Name ;
		cout<< "  部门编号: "<<this->m_EmpArray[i]->m_DeptId<<endl ;
	}
	*/
}

void workerManager::init_Emp()
{

	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)//读一行数据
	{
		/* 写法错误，m_EmpArray 必须先分配好空间，数组本身要提前分配，下面这样写是野指针
		this->m_EmpArray[num]->m_Id = id;
		this->m_EmpArray[num]->m_Name = name;
		this->m_EmpArray[num]->m_DeptId = did;
		num++;
		*/
		Worker* worker = NULL;
		if (did == 1)//根据不同部门创建不同类
			worker = new Employee(id, name, did);
		else if(did==2)
			worker=new Manager(id, name, did);
		else
			worker = new Boss(id, name, did);
		this->m_EmpArray[num] = worker;
		num++;
		
	}
	this->m_EmpNum = num;
	ifs.close();

}
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)//读一行数据
	{
		//统计人数
		num++;
	}
	return num;

}
void workerManager::Add_Emp()
{
	cout << "请输入增加职工数量: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];//// 二级指针指向指针数组Worker
		//将原空间内容存放到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0;i < addNum;i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;

			cout << " 请选择该职工的岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout<< "2、经理" << endl;
			cout<< "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "输入无效，已跳过该职工" << endl;
				continue;  // 跳过本次循环，执行下一个i,不写入空指针
			}
			assert(this->m_EmpNum + i < newSize);//“我断言：this->m_EmpNum + i 一定小于 newSize。如果这都不成立，那程序肯定出 bug 了，立刻停下来告诉我！
			newSpace[this->m_EmpNum + i] = worker;//如果输入的不是1，2，3  ,newSpace=NULL ,后续调用 newSpace[i]->showInfo() 时，对 NULL 解引用，程序崩溃

			//delete worker;worker是一个指针，指向worker类，上一行这个指针存入newSpace数组，delete会销毁创建的对象
		}
		delete[] this->m_EmpArray;//释放原有空间
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		cout << "成功添加 " << addNum << " 名新职工！" << endl;
	}
	else
		cout << "输入有误" << endl;
	system("pause");
	system("cls");

}

void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
void workerManager::Show_Menu()
{
	cout << "*******************************" << endl;
	cout << "****欢迎使用职工管理系统！*****" << endl;
	cout << "*****0、退出管理程序***********" << endl;
	cout << "*****1、添加职工信息***********" << endl;
	cout << "*****2、显示职工信息***********" << endl;
	cout << "*****3、删除职工信息***********" << endl;
	cout << "*****4、查找职工信息***********" << endl;
	cout << "*****5、修改职工信息***********" << endl;
	cout << "*****6、按照编号排序***********" << endl;
	cout << "*****7、清空所有文档***********" << endl;
	cout << "*******************************" << endl;


}
void workerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "记录为空" << endl;
	else
	{
		for (int i = 0;i < this->m_EmpNum;i++)
			this->m_EmpArray[i]->showInfo();//利用多态调用接口
	}
	system("pause");
	system("cls");
}

int workerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{ 

			index = i;
		    break;
		}

	}
	return index;
}
void workerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		int id = -1;
		cout << "请输入要删除的职工ID: " << endl;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)//说明职工存在
		{
			for (int i = ret;i < this->m_EmpNum-1;i++)
			{

			}
		}
		else
			cout << "删除失败，职工不存在" << endl;
	}
}

void workerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//立即终止整个进程，无论在哪调用
}
workerManager::~workerManager()
{
	
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
};