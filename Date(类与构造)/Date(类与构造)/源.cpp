#include<iostream>
#include<stdio.h>
using namespace std;
class Date
{
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}
Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}
void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::print()
{
	printf("Today is %d/%02d/%02d\n", year, month, day);
}
void Date::addOneDay()
{
	if (month == 2)
	{
		if ((year % 4 == 0) && (year % 100 != 0))
		{
			if (day == 29)
			{
				month++;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
			else
			{
				day++;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
		}
		else if ((year % 100 == 0) && (year % 400 == 0))
		{
			if (day == 29)
			{
				month++;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
			else
			{
				day++;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
		}
		else
		{
			if (day == 28)
			{
				month++;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
			else
			{
				day++;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
		}
	}
	else
	{
		if (day == 30)
		{
			if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			{
				month++;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
			else
			{
				day++;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
		}
		else if (day == 31)
		{
			if (month == 12)
			{
				year++;
				month = 1;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
			else
			{
				month++;
				day = 1;
				printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
			}
		}
		else
		{
			day++;
			printf("Tomorrow is %d/%02d/%02d\n", year, month, day);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Date a;
		int y, m, d;
		cin >> y >> m >> d;
		a.setDate(y, m, d);
		a.print();
		a.addOneDay();
	}
	return 0;
}/*��Ŀ����
������һ��������Ķ��壬��������ʵ�������еķ��������������������ɶ������֮��



ע�⣬���ж���������ʱ��Ҫ������¡����ꡢ������ж�

����9.��30�յ�������10��1�գ�12��31�յ������ǵڶ����1��1��

2��28�յ�����Ҫ�����Ƿ����꣬��������2��29�գ�����������3��1��

����
�������ݵ�����t

��һ��������ݵ��� �� ��

..........

Ҫ���һ�����ڵ������ճ�ʼ�����ù��캯�����ڶ������ڵ������ճ�ʼ������setDate�����������������ֲ��ù��캯�������ĸ������ֲ���setDate�������Դ����ơ�

���
������������

������������

��������
4
2012 1 3
2012 2 28
2012 3 31
2012 4 30
�������
Today is 2012/01/03
Tomorrow is 2012/01/04
Today is 2012/02/28
Tomorrow is 2012/02/29
Today is 2012/03/31
Tomorrow is 2012/04/01
Today is 2012/04/30
Tomorrow is 2012/05/01*/