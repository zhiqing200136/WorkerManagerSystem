#pragma once
#include<iostream>
#include"worker.h"
#include<fstream>
using namespace std;
#define FILENAME "empFILE.txt"
//ְ��������
class managersystem{
public:
	managersystem();

	void menu();//�˵�����

	void SystemExit();//�˳�ϵͳ



	void Add_emp();//�����Ա


	~managersystem();

	void save();//�����ļ�


	bool m_fileIsEmpty;//�ж��ļ��Ƿ�Ϊ�յı�־

	int get_EmpNumber();//ͳ��Ա������

	void Init_Emp();//��ʼ��Ա��

	void Show_Emp();

	void Del_Emp();//ɾ��Ա��

	int m_num;//��¼����

	int IsExist(int id);//�Ƿ����ְԱ����������

	void Mod_Emp();//�޸�ְԱ��Ϣ

	void Find_Emp();//����ְԱ��Ϣ

	void Clear_File();//ɾ���ļ�


	worker** m_array;//ְ������ָ��
};
