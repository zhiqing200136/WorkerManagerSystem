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
	cout << "ְԱ��ţ�" << this->m_id
		<< "\tְԱ������" << this->m_name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}
string employee::GetDeptName()
{
	return string("��ͨԱ��");
}