#include "employee.h"
#include <iostream>
using namespace std;
	
employee::employee(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void employee::ShowInfo()
{
	cout << "职员编号：" << this->m_id
		<< "\t职员姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}
string employee::GetDeptName()
{
	return string("普通员工");
}