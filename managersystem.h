#pragma once
#include<iostream>
#include"worker.h"
#include<fstream>
using namespace std;
#define FILENAME "empFILE.txt"
//职工管理类
class managersystem{
public:
	managersystem();

	void menu();//菜单界面

	void SystemExit();//退出系统



	void Add_emp();//添加人员


	~managersystem();

	void save();//保存文件


	bool m_fileIsEmpty;//判断文件是否为空的标志

	int get_EmpNumber();//统计员工数量

	void Init_Emp();//初始化员工

	void Show_Emp();

	void Del_Emp();//删除员工

	int m_num;//记录人数

	int IsExist(int id);//是否存在职员并返回其编号

	void Mod_Emp();//修改职员信息

	void Find_Emp();//查找职员信息

	void Clear_File();//删除文件


	worker** m_array;//职工数组指针
};
