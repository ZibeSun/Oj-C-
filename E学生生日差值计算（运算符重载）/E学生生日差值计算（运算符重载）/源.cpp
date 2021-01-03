#include<iostream>
using namespace std;
class Student
{
protected:
	string name;
	int year;
	int month;
	int day;
public:
	Student()
	{
		name = "����";
		year = 2000;
		month = 1;
		day = 1;
	}
	void set(string n, int y, int m, int d)
	{
		name = n;
		year = y;
		month = m;
		day = d;
	}
	bool isLeap()
	{
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
			return true;
		else
			return false;
	}
	string getname()
	{
		return name;
	}
	friend int operator-(Student& a, Student& b);
};
int operator-(Student& a, Student& b)
{
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int ms[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (a.year > b.year)
	{
		if ((a.year - b.year) == 1)
		{
			int asum = 0, bsum = 0, sum = 0;
			if (a.isLeap())
			{
				for (int i = 0; i < a.month-1; i++)
				{
					asum += ms[i];
				}
				asum += a.day;
			}
			else
			{
				for (int i = 0; i < a.month-1; i++)
				{
					asum += m[i];
				}
				asum += a.day;
			}
			if (b.isLeap())
			{
				int i;
				for (i = 11; i > b.month-1; i--)
				{
					bsum += ms[i];
				}
				bsum += ms[i] - b.day;
			}
			else
			{
				int i;
				for (i = 11; i > b.month-1; i--)
				{
					bsum += m[i];
				}
				bsum += m[i] - b.day;
			}
			sum = asum + bsum;
			return sum;
		}
		else
		{
			int asum = 0, bsum = 0, msum = 0, sum = 0;
			if (a.isLeap())
			{
				for (int i = 0; i < a.month-1; i++)
				{
					asum += ms[i];
				}
				asum += a.day;
			}
			else
			{
				for (int i = 0; i < a.month-1; i++)
				{
					asum += m[i];
				}
				asum += a.day;
			}
			if (b.isLeap())
			{
				int i;
				for (i = 11; i > b.month-1; i--)
				{
					bsum += ms[i];
				}
				bsum += ms[i] - b.day;
			}
			else
			{
				int i;
				for (i = 11; i > b.month-1; i--)
				{
					bsum += m[i];
				}
				bsum += m[i] - b.day;
			}
			int year;
			year = b.year;
			for (int i = 1; i < (a.year - b.year); i++)
			{
				if (((year + i) % 400 == 0) || (((year + i) % 4 == 0) && ((year + i) % 100 != 0)))
					msum += 366;
				else
					msum += 365;
			}
			sum = asum + bsum + msum;
			return sum;
		}
	}
	else if (a.year < b.year)
	{
		if ((b.year - a.year) == 1)
		{
			int asum = 0, bsum = 0, sum = 0;
			if (b.isLeap())
			{
				for (int i = 0; i < b.month-1; i++)
				{
					bsum += ms[i];
				}
				bsum += b.day;
			}
			else
			{
				for (int i = 0; i < b.month-1; i++)
				{
					bsum += m[i];
				}
				bsum += b.day;
			}
			if (a.isLeap())
			{
				int i;
				for (i = 11; i > a.month-1; i--)
				{
					asum += ms[i];
				}
				asum += ms[i] - a.day;
			}
			else
			{
				int i;
				for (i = 11; i > a.month-1; i--)
				{
					asum += m[i];
				}
				asum += m[i] - a.day;
			}
			sum = asum + bsum;
			return sum;
		}
		else
		{
			int asum = 0, bsum = 0, sum = 0, msum = 0;
			if (b.isLeap())
			{
				for (int i = 0; i < b.month-1; i++)
				{
					bsum += ms[i];
				}
				bsum += b.day;
			}
			else
			{
				for (int i = 0; i < b.month-1; i++)
				{
					bsum += m[i];
				}
				bsum += b.day;
			}
			if (a.isLeap())
			{
				int i;
				for (i = 11; i > a.month-1; i--)
				{
					asum += ms[i];
				}
				asum += ms[i] - a.day;
			}
			else
			{
				int i;
				for (i = 11; i > a.month-1; i--)
				{
					asum += m[i];
				}
				asum += m[i] - a.day;
			}
			int year;
			year = a.year;
			for (int i = 1; i < (b.year - a.year); i++)
			{
				if (((year + i) % 400 == 0) || (((year + i) % 4 == 0) && ((year + i) % 100 != 0)))
					msum += 366;
				else
					msum += 365;
			}
			sum = asum + bsum + msum;
			return sum;
		}
	}
	else if (a.year == b.year)
	{
		int asum = 0, bsum = 0, sum = 0;
		if (a.isLeap())
		{
			for (int i = 0; i < a.month-1; i++)
			{
				asum += ms[i];
			}
			asum += a.day;
		}
		else
		{
			for (int i = 0; i < a.month-1; i++)
			{
				asum += m[i];
			}
			asum += a.day;
		}
		if (b.isLeap())
		{
			for (int i = 0; i < b.month-1; i++)
			{
				bsum += ms[i];
			}
			bsum += b.day;
		}
		else
		{
			for (int i = 0; i < b.month-1; i++)
			{
				bsum += m[i];
			}
			bsum += b.day;
		}
		if(asum > bsum)
		{
			sum = asum - bsum;
		}
		else if (asum < bsum)
		{
			sum = bsum - asum;
		}
		return sum;
	}
}
int main()
{
	int t;
	cin >> t;
	Student* p = new Student[t];
	for (int i = 0; i < t; i++)
	{
		string n;
		int y;
		int m;
		int d;
		cin >> n >> y >> m >> d;
		p[i].set(n, y, m, d);
	}
	int sum, zsum = 0, k=0,l=0;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			sum = p[i] - p[j];
			if (sum > zsum)
			{
				zsum = sum;
				k = i;
				l = j;
			}
		}
	}
	cout << p[k].getname() << "��" << p[l].getname() << "����������Ϊ" << zsum << "�졣";
}
/*��Ŀ����
����һ��ѧ����Student��������ѧ���������������ꡢ�¡��� ���ض��� ��-����ʵ������ѧ��֮����������ıȽϡ����������صġ�-���������������ѧ��������������������˵������Լ����������
����
��һ�У���������Ҫ�����ѧ��������
�ڶ��п�ʼ����������ÿ��ѧ���������������ꡢ�¡��ա�
���
�������������������˵������Լ����������
��������
3
Tom 1995 1 1
Joe 1995 2 28
Jimmy 1996 1 8
�������
Tom��Jimmy����������Ϊ372�졣*/