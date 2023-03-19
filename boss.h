#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//普通员工类
class boss :public worker {
public:
	boss(int id, string name, int number);
	//显示个人信息
	virtual void ShowInfo();
	//获得岗位名称
	virtual string GetDeptName();
};