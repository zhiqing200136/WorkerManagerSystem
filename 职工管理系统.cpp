#include<iostream>
#include "managersystem.h"
#include"worker.h"
#include"boss.h"
using namespace std;
int main()
{
	managersystem ms;
	int choice;
	while (true)
	{
		ms.menu();
		cout << "请输入您想实现的功能序号：" << endl;
		cin >> choice;
		while (choice < 0 || choice>7)
		{
			cout << "输入序号有误，请重新输入！" << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 0:
			ms.SystemExit();
			break;
		case 1:
			ms.Add_emp();
			break;
		case 2:
			ms.Show_Emp();
			break;
		case 3:
			ms.Del_Emp();
			break;
		case 4:																																																																																																																																																																																																																																																																																																																														
			ms.Mod_Emp();
			break;
		case 5:
			ms.Find_Emp();
			break;
		case 6:
			ms.Clear_File();
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}