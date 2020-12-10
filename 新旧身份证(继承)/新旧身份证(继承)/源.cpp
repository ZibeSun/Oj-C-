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
	bool check() //���������Ƿ�Ϸ�
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
		cout << year << "��" << month << "��" << day << "��" << " ";
	}
};
class COldID
{
private:
	char* p_id15 = new char[99];
	char* p_name = new char[99]; //15λ���֤���룬����
	CDate birthday; //��������
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
	bool check15() //��֤15λ���֤�Ƿ�Ϸ�
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
	char* p_name = new char[99]; //15λ���֤���룬����
	CDate birthday; //��������
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
			cout << "����" << endl;
		else
			cout << validyear << "��" << endl;
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
/*��Ŀ����
��������ʽ����һ��������CDate������15λ���֤�ŵľ����֤��COldID:

class CDate

{

private:

int year, month, day;

public:

CDate(int,int,int);

bool check(); //���������Ƿ�Ϸ�

bool isLeap();

void print();

};

class COldID

{

private:

char *p_id15, *p_name; //15λ���֤���룬����

CDate birthday; //��������

public:

COldID(char *p_idval, char *p_nameval, CDate &day);

bool check(); //��֤15λ���֤�Ƿ�Ϸ�

void print();

~COldID();

};

Ȼ����COldIDΪ��������18λ���֤�ŵ������֤��CNewID,������3�����ݳ�Ա:p_id18(18λ����)��issueday(ǩ������)��validyear(��Ч�ڣ�����)�������¶���check()��print()��

���֤��18λУ��������ɷ�����

1�������֤����ǰ17λ���ֱ����7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2��Ȼ������ӡ�

2����17λ���ֺ�ϵ���˼ӵĺͳ���11���õ�������

3��������У����Ķ�Ӧ��ϵΪ1,0,X,9,8,7,6,5,4,3,2��Ҳ�������������3�����֤��18λ����9�����������2�����֤�����һλ�������X��

����������һ����������󣬲���������������check()��������false�������illegal id���������print()������֤��Ϣ��check()�����֤�Ϸ��Խ�����֤�Ĺ���

1. ȷ��18λ�����Ǵ�15λ������չ�ģ��ҵ�18λУ������ȷ.

2. ���֤�еĳ������ںϷ�.

3. ���֤�����в����Ƿ��ַ�.

4. ���֤����ĳ�����ȷ.

5. ���֤Ŀǰ������Ч����(�ٶ���ǰ����Ϊ2015��4��7��).

6.���֤ǩ�����ڵ���Ч��.

����
�������ݵ����� t

��һ�����������������������ա�15λ���֤���롢18λ���֤���롢ǩ�����������ա���Ч��(100�갴���ڴ���)

�ڶ������������������������ա�15λ���֤���롢18λ���֤���롢ǩ�����������ա���Ч��(100�갴���ڴ���)

......

���
��һ��������

��һ����18λ���֤����Ϣ(���롢ǩ�����ں���Ч�ڣ���"illegal id"

�ڶ���������

�ڶ�����18λ���֤����Ϣ(���롢ǩ�����ں���Ч�ڣ���"illegal id"

......

��������
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
�������
AAAA
440301198802281133 2006��1��20�� 20��
BBBB
illegal id
CCCC
illegal id
DDDD
illegal id
EEEE
illegal id
FFFF
432831196411150810 2015��8��7�� ����
GGGG
illegal id
HHHH
illegal id
IIII
illegal id
JJJJ
illegal id*/