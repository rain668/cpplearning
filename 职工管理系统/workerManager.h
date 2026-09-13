#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"


using namespace std;


class workerManager
{
public:
	workerManager();
	void Show_Menu();
	void Addinfo();
	void ExitSystem();
	void Add_Emp();
	void save();
	void init_Emp();//初始化数组
	void show_Emp();
	int IsExist(int id);//先判断是否存在 -1不存在，存在返回数组下标
	void Del_Emp();
	int get_EmpNum();//统计文件中人数
	~workerManager();


	//记录文件中的人数个数
	int  m_EmpNum;
	//员工数组的指针
	Worker** m_EmpArray;
	//标志文件是否为空
	bool m_FileIsEmpty;
};

