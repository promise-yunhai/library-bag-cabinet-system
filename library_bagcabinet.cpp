#include<iostream>
#include <iomanip>
#include <Windows.h>
#include <mysql.h>
#include"string"
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#define N 100

int f = 0;
using namespace std;
string p;


void menu();
class student
{
public:
	void show();
	friend class StudentList;
private:
	string num, name, sex, major, address, tel;
	int age, floors;
};


class StudentList
{
private:
	student w[N];
	int NUM; //��������ԤԼ���������Ŀ
	int count; //������ʱ��¼��ǰ�����ڼ��������
public:
	void mysql_add(); //�����ԤԼ��Ϣ¼��
	void mysql_search(); //�����ԤԼ��Ϣ����
	void mysql_dele(); //�����ԤԼ��Ϣɾ��
	void mysql_modify(); //�����ԤԼ��Ϣ�޸�
	void mysql_showstudent();//��ʾ�����ԤԼ��Ϣ����Ļ��
	StudentList() {
		NUM = 0;
		count = 0;
	}
};
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;


void menu() //��ʾ�˵�
{
	cout << endl;
	cout << "ͼ��������ԤԼ��Ϣ����ϵͳ���˵�  " << endl;
 	cout << "    1.�����ԤԼ��Ϣ���  " << endl;
	cout << "    2.�����ԤԼ��Ϣ�޸�  " << endl;
	cout << "    3.�����ԤԼ��Ϣɾ��  " << endl;
	cout << "    4.�����ԤԼ��Ϣ����  " << endl;
	cout << "    5.�����ԤԼ��Ϣ��ʾ  " << endl;
	cout << "    0.�˳�   " << endl;
 	cout << endl;
}

void domain() //���˵�����ʵ��
{

	StudentList wl;
	while (1)
	{
		system("cls");
		menu();
		cout << "��ѡ������ܱ�ţ�0~5" << endl;
		int i1;
		cin >> i1;
		while (!(i1 >= 0 && i1 <= 5))
		{
			cout << "�����������������룺" << endl;
			cin >> i1;
		}
		switch (i1)
		{
		case 1:wl.mysql_add(); break;
		case 2:wl.mysql_modify(); break;
		case 3:wl.mysql_dele(); break;
		case 4:wl.mysql_search(); break;
		case 5:wl.mysql_showstudent(); break;
		case 0:cout << "ϵͳ�˳�����" << endl;
			exit(0);
		default:
			break;
		}
		cout << "�Ƿ񷵻����˵�? Y/N" << endl;
		cin >> p;
		if (p == "n" || p == "N")
		{
			cout << "ϵͳ�˳�����" << endl;
			exit(0);
		}
	}
}

void StudentList::mysql_add() //�����ԤԼ��Ϣ��Ӻ���ʵ��
{
    char sno[40];
    char name[40];
    char sex[40];
    char major[40];
    char age[40];
    char floors[40];
    char address[40];
    char phone[40];
    char sqlstr[1024];  //������

	cout << "�����������ԤԼ��Ϣ:" << endl;
	cout << "ѧ��:";
	string num;
	cin >> num;
	w[NUM].num = num;

	cout << "����:"; cin >> w[NUM].name;
	cout << "�Ա�:"; cin >> w[NUM].sex;
	cout << "רҵ:"; cin >> w[NUM].major;
	cout << "����:"; cin >> w[NUM].age;
	cout << "¥��:"; cin >> w[NUM].floors;
	cout << "���к�:"; cin >> w[NUM].address;
	cout << "�绰:"; cin >> w[NUM].tel;
	++NUM;
	count = NUM;

    int len = sprintf(sqlstr, "INSERT INTO student (sno,name,sex,major,age,floors,phone)\
							  VALUES('%s','%s','%s','%s','%s','%s''%s');",sno,name,sex,major,age,floors,phone);
    mysql_query(&mysql, sqlstr);

    if (len < 0)
        cout << "�������ʧ��\n";
    else
        cout << "������ݳɹ�\n";
    system("pause");
    system("cls");

}

void student::show() //�����ԤԼ��Ϣ��ʾ����ʵ��
{
	cout << "ѧ��:" << num << endl;
	cout << "����:" << name << endl;
	cout << "�Ա�:" << sex << endl;
	cout << "����:" << age << endl;
    cout << "�绰:" << tel << endl;
    cout << "רҵ:" << major << endl;
	cout << "¥��:" << floors << endl;
	//cout << "���к�:" << address << endl;

	cout << endl;
}

void StudentList::mysql_modify() //�����ԤԼ��Ϣ�޸ĺ���ʵ��
{
    int commond;
    char str[40];
    char str1[40];
    char sqlstr[1024];

	if (NUM <= 0)
	{
		cout << "û�������ԤԼ��Ϣ���룬ϵͳ���������˵�" << endl;
		menu();
	}
	cout << "��������Ҫ�޸���Ϣ������ѧ�ţ�" << endl;
	string num1;
	cin >> num1;
	int j = 0, k;
	int flag = 1;
	while (flag)
	{
		for (; j < count; j++)
		{
			if (num1 == w[j].num)
			{
				flag = 0;
				k = j;
				break;
			}
		}
		if (flag)
		{
			cout << "�����ڴ�Ա�������������룺" << endl;
			j = 0;
			cin >> num1;
		}
	}
	cout << "��ѡ�����������ϢΪ��" << endl;
	cout << " ѧ��:" << w[k].num << endl;
	cout << " ����:" << w[k].name << endl;
	cout << " �Ա�:" << w[k].sex << endl;
	cout << " רҵ:" << w[k].major << endl;
	cout << " ����:" << w[k].age << endl;
	cout << " ¥��:" << w[k].floors << endl;
	cout << " ���к�:" << w[k].address << endl;
	cout << " �绰:" << w[k].tel << endl;
	cout << endl;
	cout << " 1.�޸�ѧ�� " << endl;
	cout << " 2.�޸����� " << endl;
	cout << " 3.�޸��Ա� " << endl;
	cout << " 4.�޸�רҵ " << endl;
	cout << " 5.�޸����� " << endl;
	cout << " 6.�޸�¥�� " << endl;
	cout << " 7.�޸����к� " << endl;
	cout << " 8.�޸ĵ绰 " << endl;
	cout << " 0.�������˵� " << endl;
	cout << endl;
	cout << "��ѡ�����ֱ��0~8" << endl;
	int i3;
	cin >> i3;
	while (i3 < 0 || i3>1000)
	{
		cout << "�����������������룺" << endl;
		cin >> i3;
	}
	switch (i3)
	{
	case 1:
		cout << "�������µ������ѧ��:";
		cin >> w[k].num;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 2:
		cout << "�������µ����������:";
		cin >> w[k].name;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 3:
		cout << "�������µ�������Ա�:";
		cin >> w[k].sex;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 4:
		cout << "�������µ������רҵ:";
		cin >> w[k].major;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 5:
		cout << "�������µ����������:";
		cin >> w[k].age;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 6:
		cout << "�������µ������¥��:";
		cin >> w[k].floors;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 7:
		cout << "�������µ���������к�:";
		cin >> w[k].address;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 8:
		cout << "�������µ������绰:";
		cin >> w[k].tel;
		cout << "�޸���Ϣ�ѱ��棬�ַ������˵���" << endl;
		menu();
		break;
	case 0:
		menu();
	default:
		break;
	}
}

void StudentList::mysql_showstudent() //�����ԤԼ��Ϣ��ʾ����ʵ��
{
	mysql_query(&mysql,"select * from student");
    res = mysql_store_result(&mysql);
    printf("sno\t\tname\tsex\tmajor\tage\tfloors\tphone\tn");
    while (row = mysql_fetch_row(res))
    {
        cout << left << setw(16) << row[0];
        cout << left << setw(8) << row[1];
        cout << left << setw(8) << row[2];
        cout << left << setw(16) << row[3];
        cout << left << setw(16) << row[4];
        cout << left << setw(16) << row[5];
        cout << left << setw(16) << row[6];
        cout << endl;
    }
    mysql_free_result(res);

    system("pause");
    system("cls");

}


void StudentList::mysql_search() //�����ԤԼ��Ϣ��ѯ����ʵ��
{
	if (NUM <= 0)
	{
		cout << "û�������ԤԼ��Ϣ���룬ϵͳ���������˵�" << endl;
		menu();
	}
	else
    cout << endl;
	cout << " ��ѡ����ҷ�ʽ�� " << endl;
	cout << " 1.��ѧ�Ų��� " << endl;
	cout << " 2.���������� " << endl;
	cout << " 3.��רҵ���� " << endl;
	cout << " 0.�������˵� " << endl;

	cout << endl;
	cout << "��ѡ�����ֱ��0~3" << endl;
	int i4;
	cin >> i4;
	while (i4 < 0 || i4>3)
	{
		cout << "�����������������룺" << endl;
		cin >> i4;
	}
	if (i4 == 1)
	{
		string num2;
		cout << "������Ҫ��ѯ��������ѧ�ţ�" << endl;
		cin >> num2;
		int j = 0, k;
		int flag = 1;
		while (flag)
		{
			for (; j < count; j++)
			{
				if (num2 == w[j].num)
				{
					flag = 0;
					k = j;
					cout << "��ѯ�������ԤԼ��Ϣ���£�" << endl;
					cout << " ѧ��:" << w[k].num << endl;
					cout << " ����:" << w[k].name << endl;
					cout << " �Ա�:" << w[k].sex << endl;
					cout << " רҵ:" << w[k].major << endl;
					cout << " ����:" << w[k].age << endl;
					cout << " ¥��:" << w[k].floors << endl;
					cout << " ���к�:" << w[k].address << endl;
					cout << " �绰:" << w[k].tel << endl;
					break;
				}
			}
			if (flag)
			{
				flag = 0;
				cout << "�����ڴ������!!\n�������˵�" << endl;
				break;
			}
		}
	}
	else if (i4 == 2)
	{
		string name2;
		cout << "������Ҫ��ѯ��������������" << endl;
		cin >> name2;
		int j2 = 0, k2;
		int flag2 = 1;
		while (flag2)
		{
			for (; j2 < count; j2++)
			{
				if (name2 == w[j2].name)
				{
					flag2 = 0;
					k2 = j2;
					cout << "��ѯ�������ԤԼ��Ϣ���£�" << endl;
					cout << " ѧ��:" << w[k2].num << endl;
					cout << " ����:" << w[k2].name << endl;
					cout << " �Ա�:" << w[k2].sex << endl;
					cout << " רҵ:" << w[k2].major << endl;
					cout << " ����:" << w[k2].age << endl;
					cout << " ¥��:" << w[k2].floors << endl;
					cout << " ���к�:" << w[k2].address << endl;
					cout << " �绰:" << w[k2].tel << endl;
					break;
				}
			}
			if (flag2)
			{
				flag2 = 0;
				cout << "�����ڴ������!!\n�������˵�" << endl;
				break;
			}
		}

	}
	else if (i4 == 3)
	{
		string major2;
		cout << "������Ҫ��ѯ��������רҵ��" << endl;
		cin >> major2;
		int j4 = 0, k4;
		int flag4 = 1;
		while (flag4)
		{
			for (; j4 < count; j4++)
			{
				if (major2 == w[j4].major)
				{
					flag4 = 0;
					k4 = j4;
					cout << "��ѯ�������ԤԼ��Ϣ���£�" << endl;
					cout << " ѧ��:" << w[k4].num << endl;
					cout << " ����:" << w[k4].name << endl;
					cout << " �Ա�:" << w[k4].sex << endl;
					cout << " רҵ:" << w[k4].major << endl;
					cout << " ����:" << w[k4].age << endl;
					cout << " ¥��:" << w[k4].floors << endl;
					cout << " ���к�:" << w[k4].address << endl;
					cout << " �绰:" << w[k4].tel << endl;
					break;
				}
			}
			if (flag4)
			{
				flag4 = 0;
				cout << "�����ڴ��������Ϣ!!\n�������˵�" << endl;
				break;
			}
		}

	}
	else if (i4 == 0)
		menu();
}

void StudentList::mysql_dele() //�����ԤԼ��Ϣɾ������ʵ��
{
    char str[40];
    char sqlstr[1024];

	if (NUM <= 0)
	{
		cout << "û�������ԤԼ��Ϣ���룬ϵͳ���������˵�" << endl;
		menu();
	}
	else{
        cout << "��������Ҫɾ����Ϣ������ѧ�ţ�" << endl;
	string str;
	cin >> str;

	int len = sprintf(sqlstr, "delete from student where sno=%s", str);
    mysql_query(&mysql, sqlstr);

    if (len < 0)
        cout << "ɾ������ʧ��\n";
    else
        cout << "ɾ�����ݳɹ�\n";
    system("pause");
    system("cls");
}
}

int main()
{
    while (1)
    {
        mysql_init(&mysql);

        mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

        if (!mysql_real_connect(&mysql, "localhost", "root", "1314520", "student", 3306, NULL, 0))
            cout << "����ʧ�ܣ����Ժ�����" << endl;
        else
        {
            domain();
        }
    }
	return 0;
}

