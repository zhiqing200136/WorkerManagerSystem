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
	cout << "ְԱ��ţ�" << this->m_id
		<< "\tְԱ������" << this->m_name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ�𣺸���������˾ְ��" << endl;
}
string boss::GetDeptName()
{
	return string("�ϰ�");
}