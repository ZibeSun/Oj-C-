#include<iostream>
using namespace std;
class Soft
{
protected:
	char* name = new char[99];
	char type;
	char media;
public:
	Soft(char *n,char ty,char me)
	{
		name = n;
		type = ty;
		media = me;
	}
	Soft(Soft& s)
	{
		name = s.name;
		type = 'B';
		media = 'H';
	}
	void print()
	{
		cout << "name:" << name << endl;
		if (type == 'O')
		{
			cout << "type:original" << endl;
		}
		else if (type == 'B')
		{
			cout << "type:backup" << endl;
		}
		else if (type == 'T')
		{
			cout << "type:trial" << endl;
		}
		if (media == 'D')
		{
			cout << "media:optical disk" << endl;
		}
		else if (media == 'U')
		{
			cout << "media:USB disk" << endl;
		}
		else if (media == 'H')
		{
			cout << "media:hard disk" << endl;
		}
	}
};
class CDate
{
private:
	int year, month, day;
public:
	CDate(int y, int m, int d) 
	{ year = y; month = m; day = d; }
	bool isLeapYear() 
	{ return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	int getYear() 
	{ return year; }
	int getMonth() 
	{ return month; }
	int getDay() 
	{ return day; }
	int getDayofYear()
	{
		int i, sum = day+23;
		int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int b[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

		if (year > 2015)
		{
			sum = 0;
			int f,k,g=0;
			f = year - 2015;
			k = f - 1;
			for (int i = 0; i < k; i++)
			{
				if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				{
					g += 366;
				}
				else
				{
					g += 365;
				}
			}
			sum = 268 + g;
			if (isLeapYear())
				for (i = 0; i < month; i++)   sum += b[i];
			else
				for (i = 0; i < month; i++)   sum += a[i];
		}

		else if (year == 2015)
		{
			if (isLeapYear())
				for (i = 5; i < month; i++)   sum += b[i];
			else
				for (i = 5; i < month; i++)   sum += a[i];
		}
		

		return sum;
	}
	void print(int s)
	{
		cout << "this software is going to be expired in " << s << " days" << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char* n=new char[99];
		char ty;
		char me;
		int y, m, d;
		cin >> n >> ty >> me >> y >> m >> d;
		CDate a(y, m, d);
		Soft p1(n, ty, me);
		p1.print();
		if ((y == 0) && (m == 0) && (d == 0))
		{
			cout << "this software has unlimited use" << endl;
		}
		else if ((y < 2015) || ((y == 2015) && (m < 4)) || ((y == 2015) && (m == 4) && (d <= 7)))
		{
			cout << "this software has expired" << endl;
		}
		else
		{
			int s = a.getDayofYear();
			a.print(s);
		}
		cout << endl;
		Soft p2(p1);
		p2.print();
		if ((y == 0) && (m == 0) && (d == 0))
		{
			cout << "this software has unlimited use" << endl;
		}
		else if ((y < 2015) || ((y == 2015) && (m < 4)) || ((y == 2015) && (m == 4) && (d <= 7)))
		{
			cout << "this software has expired" << endl;
		}
		else
		{
			int s = a.getDayofYear();
			a.print(s);
		}
		cout << endl;
	}
	return 0;
}
/*��Ŀ����
�����Ϊһ�ֶ���Ҳ������������������������԰���������ơ�����(�ֱ���O��T��B��ʾԭ�桢���ð滹�Ǳ���)����Ч��������(��CDate���Ӷ����ʾ)�ʹ洢����(�ֱ���D��H��U��ʾ���̡����̺�U��)�ȡ����������ͨ���������캯����ʵ�֣���ʱ�ڿ������캯����������͸ĳɡ�B��, �洢���ʸ�Ϊ"H"���������䡣����ɸ���Ŀ������졢����ʹ�ӡ(������2015��4��7��������Ч�ڻ��ж����죬�Ƿ����)��Ա������ʵ�֡�

�����������Ч��ֹ������0��0��0�գ���ʾ���������ƣ�Ϊunlimited��������������2015��4��7��֮ǰ�����ǹ��ڣ���ʾΪexpired���������������2015��4��7��֮������ʾ֮���ʣ�����������������Ϣ�����������


��CDate���ʵ�֣�

 class CDate
{
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear()         //�������ڴӵ���1��1�����������
    {
    int i, sum=day; 
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

        if (isLeapYear())
            for(i=0;i<month;i++)   sum +=b[i];
        else
            for(i=0;i<month;i++)   sum +=a[i];

         return sum;
    }
};

����
�������ݵ����� t

��һ���������

��һ���������  ��һ�������������  ��һ�������Ч���� �� ��

�ڶ����������

�ڶ���������� �ڶ�������������� �ڶ��������Ч���� �� ��

......

���
name: ��һ���������

type: ��һ���������

media: ��һ�������������

��һ�����2015-4-7�����Ч����

name: ��һ���������

type: backup

media: hard disk

��һ�����2015-4-7�����Ч����

......

��������
3
Photoshop_CS5
O D 0 0 0
Audition_3.0
B U 2015 2 3
Visual_Studio_2010
T H 2015 5 5
�������
name:Photoshop_CS5
type:original
media:optical disk
this software has unlimited use

name:Photoshop_CS5
type:backup
media:hard disk
this software has unlimited use

name:Audition_3.0
type:backup
media:USB disk
this software has expired

name:Audition_3.0
type:backup
media:hard disk
this software has expired

name:Visual_Studio_2010
type:trial
media:hard disk
this software is going to be expired in 28 days

name:Visual_Studio_2010
type:backup
media:hard disk
this software is going to be expired in 28 days*/