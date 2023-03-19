#include "boss.h"
#include <iostream>
using namespace std;
boss::boss(int id, string name, int number)
{
	this->m_id = id;
	this->m_name = name;
	this->m_number = number;
}
void boss::ShowInfo()
{
	cout << "职员编号：" << this->m_id
		<< "\t职员姓名：" << this->m_name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：负责整个公司职务" << endl;
}
string boss::GetDeptName()
{
	return string("老板");
}