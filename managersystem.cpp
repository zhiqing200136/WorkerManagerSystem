#include"managersystem.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
managersystem::managersystem() 
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//读文件
	if (!ifs.is_open())//1.文件不存在
	{
		
		//初始化
		this->m_num = 0;
		this->m_array = NULL;
		this->m_fileIsEmpty= true;
		ifs.close();
		return;
	}
	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		
		this->m_num = 0;
		this->m_array = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在，数据不为空
	int num = this->get_EmpNumber();
	this->m_num = num;
	//开辟空间
	this->m_array = new worker * [this->m_num];
	//将文件数据存到数组中
	this->Init_Emp();

	
}
managersystem::~managersystem() 
{
	if (this->m_array != NULL)
	{
		delete[] this->m_array;
		this->m_array = NULL;
	}
}
void managersystem::menu()
{
	cout << "***********************************************" << endl;
	cout << "************欢迎来到职工管理系统***************" << endl;
	cout << "*******       0.退出管理系统         **********" << endl;
	cout << "*******       1.添加职员信息         **********" << endl;
	cout << "*******       2.显示职员信息         **********" << endl;
	cout << "*******       3.删除离职职员         **********" << endl;
	cout << "*******       4.修改职员信息         **********" << endl;
	cout << "*******       5.查找职员信息         **********" << endl;
	cout << "*******       6.清空所有文档         **********" << endl;
	cout << "***********************************************" << endl;
}



void managersystem::SystemExit()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void managersystem::Add_emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum=0;
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int NewSize = addNum + this->m_num;
		//开辟新空间
		worker** NewSpace = new worker * [NewSize];

		//将原来的数据拷贝到新空间
		if (this->m_array != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				NewSpace[i] = this->m_array[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			int num;
			string name;
			int flag = 0;
			cout << "请输入第" << i + 1 << "个新员工的编号：" << endl;
			cin >> id;
			while (flag == 0)
			{
				flag = 1;
				for (int j = 0; j < this->m_num; j++)
				{
					if (id == NewSpace[j]->m_id)
					{
						cout << "已存在该编号！请重新输入：" << endl;
						cin >> id;
						flag = 0;
						break;
					}
				}
			}
			cout << "请输入第" << i + 1 << "个新员工的姓名：" << endl;
			cin >> name;
			/*flag = 0;
			while (flag == 0)
			{
				flag = 1;
				for (int j = 0; j <this->m_num; j++)
				{
					if (id == this->m_array[i]->m_id)
					{
						cout << "已存在该编号！请重新输入：" << endl;
						cin >> id;
						flag = 0;
						break;
					}
				}
			}*/
			cout << "请输入第" << i + 1 << "个新员工的岗位：" << endl;
			cout << "1.普通职员" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> num;
			worker* worker = NULL;
			switch (num)
			{
			case 1:
				worker = new employee(id, name, num);
				break;
			case 2:
				worker = new manager(id, name, num);
				break;
			case 3:
				worker = new boss(id, name, num);
				break;
			}
			NewSpace[i + this->m_num] = worker; 
		}
		//释放原有空间
		delete[] this->m_array;
		//更改新空间的指向
		this->m_num = NewSize;
		//更新职员人数
		this->m_array = NewSpace;
		//更新职员不为空标志
		this->m_fileIsEmpty = false;
		//将数据存入文件
		this->save();
		cout << "添加成功！" << endl;
		system("pause");
	}
	else
	{
		cout << "输入有误！" << endl;
	}
}

void managersystem::save() 
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << this->m_array[i]->m_id << " "
			<< this->m_array[i]->m_name << " "
			<< this->m_array[i]->m_number << endl;
	}
	ofs.close();
}
int managersystem::get_EmpNumber() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件
	int id;
	string name;
	int number;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> number)
	{
		num++;
	}
	return num;
}

void managersystem::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int number;
	int Index = 0;
	while (ifs >> id && ifs >> name && ifs >> number)
	{
		worker* worker = NULL;
		if (number == 1)//职工
		{
			worker = new employee(id,name,number);
		}
		else if (number == 2)//经理
		{
			worker = new manager(id, name, number);
		}
		else if (number == 3)//老板
		{
			worker = new boss(id, name, number);
		}
		this->m_array[Index] = worker;
		Index++;
	}
	//关闭文件
	ifs.close();
}

void managersystem::Show_Emp()
{
	//判断文件是否为空
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			//打印员工信息
			this->m_array[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

void managersystem::Del_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
	}
	else
	{
		cout << "请输入想要删除的职员编号：" << endl;
		int id;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//职员存在，删除第index位置上的职员
		{
			//数据前移
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_array[i] = this->m_array[i + 1];
			}
			//更新人数
			this->m_num--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败！未找到该职员！" << endl;
		}
	}
	system("pause");
	system("cls");
}

int managersystem::IsExist(int id)
{
	int Index = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (id == this->m_array[i]->m_id)
		{
			//找到职工
			Index = i;
			break;
		}
	}
	return Index;
}

void managersystem::Mod_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
	}
	else
	{
		cout << "请输入修改的职工的编号" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//查找
			delete this->m_array[ret];
			int NewId;
			int NewNum;
			string NewName;
			cout << "请输入新职工编号：" << endl;
			cin >> NewId;
			cout << "请输入新职工姓名：" << endl;
			cin >> NewName;
			cout << "请输入新职工岗位：" << endl;
			cout << "1.普通职员" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> NewNum;
			worker* worker = NULL;
			switch (NewNum)
			{
			case 1:
			{
				
				worker = new employee(NewId, NewName, NewNum);
				break;
			}
			case 2:
			{
				
				worker = new manager(NewId, NewName, NewNum);
				break;
			}
			case 3:
			{
				
				worker = new boss(NewId, NewName, NewNum);
				break;
			}
			}
			//更新指针
			this->m_array[ret] = worker;
			//同步到文件中
			this->save();
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "无此员工信息！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void managersystem::Find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按职员编号查找：" << endl;
		cout << "2.按职员姓名查找：" << endl;
		int select = 0;
		cin >> select;
		while (select < 1 || select>2)
		{
			cout << "输入选项有误，请重新输入！" << endl;
			cin >> select;
		}
		switch (select)
		{
		case 1:
		{
			int id;
			cout << "请输入查找的职员编号：" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//找到职员
				cout << "查找成功！" << endl;
				this->m_array[ret]->ShowInfo();
			}
			else
			{
				//找不到职员
				cout << "找不到该职员！" << endl;
			}
			break;
		}
		case 2:
		{
			int flag=0;//查找成功的标志
			string name;
			cout << "请输入职工姓名：" << endl;
			cin >> name;
			for (int i = 0; i < this->m_num;i++)
			{
				if (name == this->m_array[i]->m_name)
				{
					flag = 1;//查找成功
					cout << "查找成功！" << endl;
					this->m_array[i]->ShowInfo();
					break;
				}
			}
			if (flag != 1)
			{
				cout << "找不到该职员！" << endl;
			}

			break;
		}
		}
	}
	system("pause");
	system("cls");
}

void managersystem::Clear_File()
{
	cout << "请重新确认是否清空" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	int select;
	cin >> select;
	while (select < 1 || select>2)
	{
		cout << "输入选项有误，请重新输入！" << endl;
		cin >> select;
	}
	switch (select)
	{
	case 1:
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_array != NULL)
		{
			//删除职员指针的每个对象
			for (int i = 0; i < this->m_num; i++)
			{
				delete this->m_array[i];
				this->m_array[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_array;
			this->m_array = NULL;
			this->m_num = 0;
			this->m_fileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
		break;
	}
	case 2:
	{
		break;
	}
	}
	system("pause");
	system("cls");
}