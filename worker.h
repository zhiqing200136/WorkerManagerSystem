#pragma once
#include <iostream>
#include<string>
using namespace std;

//��˾Ա����
class worker {
public:
	//��ʾ������Ϣ
	virtual void ShowInfo()=0;
	//��ø�λ����
	virtual string GetDeptName() = 0;
	string m_name;//����
	int m_id;//���
	int m_number;//��������
};