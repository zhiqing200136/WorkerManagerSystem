#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//��ͨԱ����
class employee:public worker {
public:
	employee(int id, string name, int number);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ø�λ����
	virtual string GetDeptName();
};