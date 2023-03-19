#pragma once
#include <iostream>
#include<string>
using namespace std;

//公司员工类
class worker {
public:
	//显示个人信息
	virtual void ShowInfo()=0;
	//获得岗位名称
	virtual string GetDeptName() = 0;
	string m_name;//姓名
	int m_id;//编号
	int m_number;//工作部门
};