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
	cout << "ְԱ��ţ�" << this->m_id
		<< "\tְԱ������" << this->m_name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ�𣺹�����ͨԱ��������ϰ������" << endl;
}
string manager::GetDeptName()
{
	return string("����");
}