#include "manager.h"
#include <iostream>
using namespace std;

manager::manager(int id,string name,int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void manager::ShowInfo()
{
	cout << "职员编号：" << this->m_id
		<< "\t职员姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：管理普通员工，完成老板的任务" << endl;
}
string manager::GetDeptName()
{
	return string("经理");
}