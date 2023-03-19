#include"managersystem.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"
managersystem::managersystem() 
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ�
	if (!ifs.is_open())//1.�ļ�������
	{
		
		//��ʼ��
		this->m_num = 0;
		this->m_array = NULL;
		this->m_fileIsEmpty= true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		
		this->m_num = 0;
		this->m_array = NULL;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����ݲ�Ϊ��
	int num = this->get_EmpNumber();
	this->m_num = num;
	//���ٿռ�
	this->m_array = new worker * [this->m_num];
	//���ļ����ݴ浽������
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
	cout << "************��ӭ����ְ������ϵͳ***************" << endl;
	cout << "*******       0.�˳�����ϵͳ         **********" << endl;
	cout << "*******       1.���ְԱ��Ϣ         **********" << endl;
	cout << "*******       2.��ʾְԱ��Ϣ         **********" << endl;
	cout << "*******       3.ɾ����ְְԱ         **********" << endl;
	cout << "*******       4.�޸�ְԱ��Ϣ         **********" << endl;
	cout << "*******       5.����ְԱ��Ϣ         **********" << endl;
	cout << "*******       6.��������ĵ�         **********" << endl;
	cout << "***********************************************" << endl;
}



void managersystem::SystemExit()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
void managersystem::Add_emp()
{
	cout << "���������ְ����������" << endl;
	int addNum=0;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int NewSize = addNum + this->m_num;
		//�����¿ռ�
		worker** NewSpace = new worker * [NewSize];

		//��ԭ�������ݿ������¿ռ�
		if (this->m_array != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				NewSpace[i] = this->m_array[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			int num;
			string name;
			int flag = 0;
			cout << "�������" << i + 1 << "����Ա���ı�ţ�" << endl;
			cin >> id;
			while (flag == 0)
			{
				flag = 1;
				for (int j = 0; j < this->m_num; j++)
				{
					if (id == NewSpace[j]->m_id)
					{
						cout << "�Ѵ��ڸñ�ţ����������룺" << endl;
						cin >> id;
						flag = 0;
						break;
					}
				}
			}
			cout << "�������" << i + 1 << "����Ա����������" << endl;
			cin >> name;
			/*flag = 0;
			while (flag == 0)
			{
				flag = 1;
				for (int j = 0; j <this->m_num; j++)
				{
					if (id == this->m_array[i]->m_id)
					{
						cout << "�Ѵ��ڸñ�ţ����������룺" << endl;
						cin >> id;
						flag = 0;
						break;
					}
				}
			}*/
			cout << "�������" << i + 1 << "����Ա���ĸ�λ��" << endl;
			cout << "1.��ְͨԱ" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		//�ͷ�ԭ�пռ�
		delete[] this->m_array;
		//�����¿ռ��ָ��
		this->m_num = NewSize;
		//����ְԱ����
		this->m_array = NewSpace;
		//����ְԱ��Ϊ�ձ�־
		this->m_fileIsEmpty = false;
		//�����ݴ����ļ�
		this->save();
		cout << "��ӳɹ���" << endl;
		system("pause");
	}
	else
	{
		cout << "��������" << endl;
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
	ifs.open(FILENAME, ios::in);//���ļ�
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
		if (number == 1)//ְ��
		{
			worker = new employee(id,name,number);
		}
		else if (number == 2)//����
		{
			worker = new manager(id, name, number);
		}
		else if (number == 3)//�ϰ�
		{
			worker = new boss(id, name, number);
		}
		this->m_array[Index] = worker;
		Index++;
	}
	//�ر��ļ�
	ifs.close();
}

void managersystem::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			//��ӡԱ����Ϣ
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
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְԱ��ţ�" << endl;
		int id;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1)//ְԱ���ڣ�ɾ����indexλ���ϵ�ְԱ
		{
			//����ǰ��
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_array[i] = this->m_array[i + 1];
			}
			//��������
			this->m_num--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְԱ��" << endl;
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
			//�ҵ�ְ��
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
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸ĵ�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//����
			delete this->m_array[ret];
			int NewId;
			int NewNum;
			string NewName;
			cout << "��������ְ����ţ�" << endl;
			cin >> NewId;
			cout << "��������ְ��������" << endl;
			cin >> NewName;
			cout << "��������ְ����λ��" << endl;
			cout << "1.��ְͨԱ" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//����ָ��
			this->m_array[ret] = worker;
			//ͬ�����ļ���
			this->save();
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "�޴�Ա����Ϣ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void managersystem::Find_Emp()
{
	if (this->m_fileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.��ְԱ��Ų��ң�" << endl;
		cout << "2.��ְԱ�������ң�" << endl;
		int select = 0;
		cin >> select;
		while (select < 1 || select>2)
		{
			cout << "����ѡ���������������룡" << endl;
			cin >> select;
		}
		switch (select)
		{
		case 1:
		{
			int id;
			cout << "��������ҵ�ְԱ��ţ�" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְԱ
				cout << "���ҳɹ���" << endl;
				this->m_array[ret]->ShowInfo();
			}
			else
			{
				//�Ҳ���ְԱ
				cout << "�Ҳ�����ְԱ��" << endl;
			}
			break;
		}
		case 2:
		{
			int flag=0;//���ҳɹ��ı�־
			string name;
			cout << "������ְ��������" << endl;
			cin >> name;
			for (int i = 0; i < this->m_num;i++)
			{
				if (name == this->m_array[i]->m_name)
				{
					flag = 1;//���ҳɹ�
					cout << "���ҳɹ���" << endl;
					this->m_array[i]->ShowInfo();
					break;
				}
			}
			if (flag != 1)
			{
				cout << "�Ҳ�����ְԱ��" << endl;
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
	cout << "������ȷ���Ƿ����" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	int select;
	cin >> select;
	while (select < 1 || select>2)
	{
		cout << "����ѡ���������������룡" << endl;
		cin >> select;
	}
	switch (select)
	{
	case 1:
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();
		if (this->m_array != NULL)
		{
			//ɾ��ְԱָ���ÿ������
			for (int i = 0; i < this->m_num; i++)
			{
				delete this->m_array[i];
				this->m_array[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_array;
			this->m_array = NULL;
			this->m_num = 0;
			this->m_fileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
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