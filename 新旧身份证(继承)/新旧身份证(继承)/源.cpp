#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class CDate
{
private:
	int year, month, day;
public:
	CDate()
	{
		year = 2000;
		month = 1;
		day = 1;
	}
	CDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	bool check() //检验日期是否合法
	{
		if ((month > 0) && (month <= 12))
		{
			if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
			{
				if ((day > 0) && (day <= 31))
					return true;
				else
					return false;
			}
			else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			{
				if ((day > 0) && (day <= 30))
					return true;
				else
					return false;
			}
			else if (month == 2)
			{
				if (isLeap())
				{
					if ((day > 0) && (day <= 29))
						return true;
					else
						return false;
				}
				else
				{
					if ((day > 0) && (day <= 28))
						return true;
					else
						return false;
				}
			}
		}
		else
			return false;
	}
	bool isLeap()
	{
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
			return true;
		else
			return false;
	}
	int getyear()
	{
		return year;
	}
	int getmonth()
	{
		return month;
	}
	int getday()
	{
		return day;
	}
	void print()
	{
		cout << year << "年" << month << "月" << day << "日" << " ";
	}
};
class COldID
{
private:
	char* p_id15 = new char[99];
	char* p_name = new char[99]; //15位身份证号码，姓名
	CDate birthday; //出生日期
public:
	COldID()
	{

	}
	COldID(char* p_nameval, CDate& birth, char* p_id15val)
	{
		strcpy(p_id15, p_id15val);
		strcpy(p_name, p_nameval);
		birthday = birth;
	}
	bool check15() //验证15位身份证是否合法
	{
		for (int i = 0; i < 15; i++)
		{
			if ((p_id15[i] < '0') || (p_id15[i] > '9'))
				return false;
		}
		if (p_id15[15] != '\0')
			return false;
		return true;
	}
	~COldID()
	{
		delete[] p_id15;
		delete[] p_name;
	}
};

class CNewID :public COldID
{
private:
	char* p_id15 = new char[99];
	char* p_name = new char[99]; //15位身份证号码，姓名
	CDate birthday; //出生日期
	char* p_id18 = new char[99];
	CDate issueday;
	int validyear;
public:
	CNewID(char* p_nameval, CDate& birth, char* p_id15val, char* p_id18val, CDate& i,int v)
	{
		strcpy(p_id15, p_id15val);
		strcpy(p_id18, p_id18val);
		strcpy(p_name, p_nameval);
		birthday = birth;
		issueday = i;
		validyear = v;
	}
	char Finalcode()
	{
		int sum=0;
		char code;
		char c[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
		int x[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
		for (int i = 0; i < 17; i++)
		{
			sum += (p_id18[i] - 48)*x[i];
		}
		sum = sum % 11;
		code = c[sum];
		return code;
	}
	bool check18()
	{
		for (int i = 0; i < 18; i++)
		{
			if ((p_id18[i] < '0') || (p_id18[i] > '9'))
				return false;
			if (i < 6)
			{
				if (p_id18[i] != p_id15[i])
					return false;
			}
			if ((i > 7) && (i < 17))
			{
				if (p_id18[i] != p_id15[i-2])
					return false;
			}
			if (i == 17)
			{
				if (p_id18[i] != Finalcode())
					return false;
			}
		}
		int b=0;
		int c = birthday.getyear() * 10000 + birthday.getmonth() * 100 + birthday.getday();
		for (int i = 6; i < 14; i++)
		{
			int d = p_id18[i] - 48;
			b = b+d * pow(10, 13-i);
		}
		if (b != c)
			return false;
		if (p_id18[18] != '\0')
			return false;
		if ((issueday.getyear() + validyear) < 2015)
			return false;
		if (!birthday.check())
			return false;
		if (!issueday.check())
			return false;
			
		return true;
	}
	void nameprint()
	{
		cout << p_name << endl;
	}
	void print()
	{
		cout << p_id18 << " ";
		issueday.print();
		if (validyear == 100)
			cout << "长期" << endl;
		else
			cout << validyear << "年" << endl;
	}
	~CNewID()
	{
		delete[] p_id15;
		delete[] p_name;
		delete[] p_id18;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char* p_nameval = new char[99];
		char* p_id15val = new char[99];
		char* p_id18val = new char[99];
		int v;
		int y1, m1, d1;
		int y2, m2, d2;
		cin >> p_nameval >> y1 >> m1 >> d1 >> p_id15val >> p_id18val >> y2 >> m2 >> d2 >> v;
		CDate birth(y1, m1, d1);	
		CDate i(y2, m2, d2);
		COldID o(p_nameval, birth, p_id15val);
		CNewID n(p_nameval, birth, p_id15val, p_id18val, i, v);
		n.nameprint();
		if (!o.check15())
		{
			cout << "illegal id" << endl;
			continue;
		}
		if (!n.check18())
		{
			cout << "illegal id" << endl;
			continue;
		}
		n.print();
	}
	return 0;
}
/*题目描述
按下述方式定义一个日期类CDate和描述15位身份证号的旧身份证类COldID:

class CDate

{

private:

int year, month, day;

public:

CDate(int,int,int);

bool check(); //检验日期是否合法

bool isLeap();

void print();

};

class COldID

{

private:

char *p_id15, *p_name; //15位身份证号码，姓名

CDate birthday; //出生日期

public:

COldID(char *p_idval, char *p_nameval, CDate &day);

bool check(); //验证15位身份证是否合法

void print();

~COldID();

};

然后以COldID为基类派生18位身份证号的新身份证类CNewID,并增加3个数据成员:p_id18(18位号码)、issueday(签发日期)和validyear(有效期，年数)，并重新定义check()和print()。

身份证第18位校验码的生成方法：

1、将身份证号码前17位数分别乘以7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2。然后将其相加。

2、将17位数字和系数乘加的和除以11，得到余数。

3、余数与校验码的对应关系为1,0,X,9,8,7,6,5,4,3,2。也即：如果余数是3，身份证第18位就是9。如果余数是2，身份证的最后一位号码就是X。

主函数定义一个派生类对象，并用派生类对象调用check()，若返回false则输出“illegal id”否则调用print()输出身份证信息。check()对身份证合法性进行验证的规则：

1. 确认18位号码是从15位号码扩展的，且第18位校验码正确.

2. 身份证中的出生日期合法.

3. 身份证号码中不含非法字符.

4. 身份证号码的长度正确.

5. 身份证目前处于有效期内(假定当前日期为2015年4月7日).

6.身份证签发日期的有效性.

输入
测试数据的组数 t

第一个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)

第二个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)

......

输出
第一个人姓名

第一个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"

第二个人姓名

第二个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"

......

样例输入
10
AAAA 1988 2 28 440301880228113 440301198802281133 2006 1 20 20
BBBB 1997 4 30 440301980808554 440301199808085541 2015 2 2 10 
CCCC 1920 5 8 530102200508011 53010219200508011X 1980 3 4 30
DDDD 1980 1 1 340524800101001 340524198001010012 1998 12 11 20
EEEE 1988 11 12 110203881112034 110203198811120340 2007 2 29 20 
FFFF 1964 11 15 432831641115081 432831196411150810 2015 8 7 100
GGGG 1996 12 10 44030196121010 44030119961210109 2014 6 7 20
HHHH 1988 7 21 440301880721X12 44030119880721X122 2006 5 11 20
IIII 1976 3 30 440301760330098 440301197603300983 2003 4 15 20
JJJJ 1955 9 5 440301550905205 440301195509051052 2004 6 4 100 
样例输出
AAAA
440301198802281133 2006年1月20日 20年
BBBB
illegal id
CCCC
illegal id
DDDD
illegal id
EEEE
illegal id
FFFF
432831196411150810 2015年8月7日 长期
GGGG
illegal id
HHHH
illegal id
IIII
illegal id
JJJJ
illegal id*/