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
	int NUM; //用来计算预约的书包柜数目
	int count; //用来暂时记录当前操作第几个书包柜
public:
	void mysql_add(); //书包柜预约信息录入
	void mysql_search(); //书包柜预约信息查找
	void mysql_dele(); //书包柜预约信息删除
	void mysql_modify(); //书包柜预约信息修改
	void mysql_showstudent();//显示书包柜预约信息在屏幕上
	StudentList() {
		NUM = 0;
		count = 0;
	}
};
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;


void menu() //显示菜单
{
	cout << endl;
	cout << "图书馆书包柜预约信息管理系统主菜单  " << endl;
 	cout << "    1.书包柜预约信息添加  " << endl;
	cout << "    2.书包柜预约信息修改  " << endl;
	cout << "    3.书包柜预约信息删除  " << endl;
	cout << "    4.书包柜预约信息查找  " << endl;
	cout << "    5.书包柜预约信息显示  " << endl;
	cout << "    0.退出   " << endl;
 	cout << endl;
}

void domain() //主菜单函数实现
{

	StudentList wl;
	while (1)
	{
		system("cls");
		menu();
		cout << "请选择管理功能编号：0~5" << endl;
		int i1;
		cin >> i1;
		while (!(i1 >= 0 && i1 <= 5))
		{
			cout << "输入有误，请重新输入：" << endl;
			cin >> i1;
		}
		switch (i1)
		{
		case 1:wl.mysql_add(); break;
		case 2:wl.mysql_modify(); break;
		case 3:wl.mysql_dele(); break;
		case 4:wl.mysql_search(); break;
		case 5:wl.mysql_showstudent(); break;
		case 0:cout << "系统退出！！" << endl;
			exit(0);
		default:
			break;
		}
		cout << "是否返回主菜单? Y/N" << endl;
		cin >> p;
		if (p == "n" || p == "N")
		{
			cout << "系统退出！！" << endl;
			exit(0);
		}
	}
}

void StudentList::mysql_add() //书包柜预约信息添加函数实现
{
    char sno[40];
    char name[40];
    char sex[40];
    char major[40];
    char age[40];
    char floors[40];
    char address[40];
    char phone[40];
    char sqlstr[1024];  //缓冲区

	cout << "请输入书包柜预约信息:" << endl;
	cout << "学号:";
	string num;
	cin >> num;
	w[NUM].num = num;

	cout << "姓名:"; cin >> w[NUM].name;
	cout << "性别:"; cin >> w[NUM].sex;
	cout << "专业:"; cin >> w[NUM].major;
	cout << "年龄:"; cin >> w[NUM].age;
	cout << "楼层:"; cin >> w[NUM].floors;
	cout << "行列号:"; cin >> w[NUM].address;
	cout << "电话:"; cin >> w[NUM].tel;
	++NUM;
	count = NUM;

    int len = sprintf(sqlstr, "INSERT INTO student (sno,name,sex,major,age,floors,phone)\
							  VALUES('%s','%s','%s','%s','%s','%s''%s');",sno,name,sex,major,age,floors,phone);
    mysql_query(&mysql, sqlstr);

    if (len < 0)
        cout << "添加数据失败\n";
    else
        cout << "添加数据成功\n";
    system("pause");
    system("cls");

}

void student::show() //书包柜预约信息显示函数实现
{
	cout << "学号:" << num << endl;
	cout << "姓名:" << name << endl;
	cout << "性别:" << sex << endl;
	cout << "年龄:" << age << endl;
    cout << "电话:" << tel << endl;
    cout << "专业:" << major << endl;
	cout << "楼层:" << floors << endl;
	//cout << "行列号:" << address << endl;

	cout << endl;
}

void StudentList::mysql_modify() //书包柜预约信息修改函数实现
{
    int commond;
    char str[40];
    char str1[40];
    char sqlstr[1024];

	if (NUM <= 0)
	{
		cout << "没有书包柜预约信息存入，系统将返回主菜单" << endl;
		menu();
	}
	cout << "请输入需要修改信息书包柜的学号：" << endl;
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
			cout << "不存在此员工，请重新输入：" << endl;
			j = 0;
			cin >> num1;
		}
	}
	cout << "你选择的书包柜的信息为：" << endl;
	cout << " 学号:" << w[k].num << endl;
	cout << " 姓名:" << w[k].name << endl;
	cout << " 性别:" << w[k].sex << endl;
	cout << " 专业:" << w[k].major << endl;
	cout << " 年龄:" << w[k].age << endl;
	cout << " 楼层:" << w[k].floors << endl;
	cout << " 行列号:" << w[k].address << endl;
	cout << " 电话:" << w[k].tel << endl;
	cout << endl;
	cout << " 1.修改学号 " << endl;
	cout << " 2.修改姓名 " << endl;
	cout << " 3.修改性别 " << endl;
	cout << " 4.修改专业 " << endl;
	cout << " 5.修改年龄 " << endl;
	cout << " 6.修改楼层 " << endl;
	cout << " 7.修改行列号 " << endl;
	cout << " 8.修改电话 " << endl;
	cout << " 0.返回主菜单 " << endl;
	cout << endl;
	cout << "请选择数字编号0~8" << endl;
	int i3;
	cin >> i3;
	while (i3 < 0 || i3>1000)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> i3;
	}
	switch (i3)
	{
	case 1:
		cout << "请输入新的书包柜学号:";
		cin >> w[k].num;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 2:
		cout << "请输入新的书包柜姓名:";
		cin >> w[k].name;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 3:
		cout << "请输入新的书包柜性别:";
		cin >> w[k].sex;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 4:
		cout << "请输入新的书包柜专业:";
		cin >> w[k].major;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 5:
		cout << "请输入新的书包柜年龄:";
		cin >> w[k].age;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 6:
		cout << "请输入新的书包柜楼层:";
		cin >> w[k].floors;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 7:
		cout << "请输入新的书包柜行列号:";
		cin >> w[k].address;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 8:
		cout << "请输入新的书包柜电话:";
		cin >> w[k].tel;
		cout << "修改信息已保存，现返回主菜单：" << endl;
		menu();
		break;
	case 0:
		menu();
	default:
		break;
	}
}

void StudentList::mysql_showstudent() //书包柜预约信息显示函数实现
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


void StudentList::mysql_search() //书包柜预约信息查询函数实现
{
	if (NUM <= 0)
	{
		cout << "没有书包柜预约信息存入，系统将返回主菜单" << endl;
		menu();
	}
	else
    cout << endl;
	cout << " 请选择查找方式： " << endl;
	cout << " 1.按学号查找 " << endl;
	cout << " 2.按姓名查找 " << endl;
	cout << " 3.按专业查找 " << endl;
	cout << " 0.返回主菜单 " << endl;

	cout << endl;
	cout << "请选择数字编号0~3" << endl;
	int i4;
	cin >> i4;
	while (i4 < 0 || i4>3)
	{
		cout << "输入有误，请重新输入：" << endl;
		cin >> i4;
	}
	if (i4 == 1)
	{
		string num2;
		cout << "请输入要查询的书包柜的学号：" << endl;
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
					cout << "查询的书包柜预约信息如下：" << endl;
					cout << " 学号:" << w[k].num << endl;
					cout << " 姓名:" << w[k].name << endl;
					cout << " 性别:" << w[k].sex << endl;
					cout << " 专业:" << w[k].major << endl;
					cout << " 年龄:" << w[k].age << endl;
					cout << " 楼层:" << w[k].floors << endl;
					cout << " 行列号:" << w[k].address << endl;
					cout << " 电话:" << w[k].tel << endl;
					break;
				}
			}
			if (flag)
			{
				flag = 0;
				cout << "不存在此书包柜!!\n返回主菜单" << endl;
				break;
			}
		}
	}
	else if (i4 == 2)
	{
		string name2;
		cout << "请输入要查询的书包柜的姓名：" << endl;
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
					cout << "查询的书包柜预约信息如下：" << endl;
					cout << " 学号:" << w[k2].num << endl;
					cout << " 姓名:" << w[k2].name << endl;
					cout << " 性别:" << w[k2].sex << endl;
					cout << " 专业:" << w[k2].major << endl;
					cout << " 年龄:" << w[k2].age << endl;
					cout << " 楼层:" << w[k2].floors << endl;
					cout << " 行列号:" << w[k2].address << endl;
					cout << " 电话:" << w[k2].tel << endl;
					break;
				}
			}
			if (flag2)
			{
				flag2 = 0;
				cout << "不存在此书包柜!!\n返回主菜单" << endl;
				break;
			}
		}

	}
	else if (i4 == 3)
	{
		string major2;
		cout << "请输入要查询的书包柜的专业：" << endl;
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
					cout << "查询的书包柜预约信息如下：" << endl;
					cout << " 学号:" << w[k4].num << endl;
					cout << " 姓名:" << w[k4].name << endl;
					cout << " 性别:" << w[k4].sex << endl;
					cout << " 专业:" << w[k4].major << endl;
					cout << " 年龄:" << w[k4].age << endl;
					cout << " 楼层:" << w[k4].floors << endl;
					cout << " 行列号:" << w[k4].address << endl;
					cout << " 电话:" << w[k4].tel << endl;
					break;
				}
			}
			if (flag4)
			{
				flag4 = 0;
				cout << "不存在此书包柜信息!!\n返回主菜单" << endl;
				break;
			}
		}

	}
	else if (i4 == 0)
		menu();
}

void StudentList::mysql_dele() //书包柜预约信息删除函数实现
{
    char str[40];
    char sqlstr[1024];

	if (NUM <= 0)
	{
		cout << "没有书包柜预约信息存入，系统将返回主菜单" << endl;
		menu();
	}
	else{
        cout << "请输入需要删除信息书包柜的学号：" << endl;
	string str;
	cin >> str;

	int len = sprintf(sqlstr, "delete from student where sno=%s", str);
    mysql_query(&mysql, sqlstr);

    if (len < 0)
        cout << "删除数据失败\n";
    else
        cout << "删除数据成功\n";
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
            cout << "进入失败，请稍后再试" << endl;
        else
        {
            domain();
        }
    }
	return 0;
}

