#include<iostream>
#include<cstring>
using namespace std;
class Phone
{
protected:
	char type;
	char* number;
	int state;
public:
	Phone(char ty, char* n, int st)
	{
		type = ty;
		number = new char[12];
		number = n;
		state = st;
	}
	Phone(Phone& s)
	{
		type = 'D';
		number = new char[12];
		for (int i = 0; i < 12; i++)
		{
			number[i] = s.number[i];
		}
		number[11] = 'X';
		number[12] = '\0';
		state = s.state;
	}
	void stop()
	{
		state = 3;
	}
	void print()
	{
		if (type == 'A')
		{
			cout << "����=����";
		}
		else if (type == 'B')
		{
			cout << "����=��ҵ";
		}
		else if (type == 'C')
		{
			cout << "����=����";
		}
		else if (type == 'D')
		{
			cout << "����=����";
		}
		cout << "||����=" << number;
		if (state == 1)
		{
			cout << "||State=����" << endl;
		}
		else if (state == 2)
		{
			cout << "||State=δ��" << endl;
		}
		else if (state == 3)
		{
			cout << "||State=ͣ��";
		}
	}
};
class Date
{
protected:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void print()
	{
		cout << "||ͣ������=" << year << "." << month << "." << day << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char ty;
		char* n=new char[11];
		int st,y,m,d;
		cin >> ty >> n >> st >> y >> m >> d;
		Phone p1(ty, n, st);
		Phone p2(p1);
		Date a(y, m, d);
		cout << "Construct a new phone " << n << endl;
		p1.print();
		cout << "Construct a copy of phone " << n << endl;
		p2.print();
		cout << "Stop the phone " << n << endl;
		p1.stop();
		p1.print();
		a.print();
		cout << "----" << endl;
	}
	return 0;
}
/*��Ŀ����
���һ������ʵ���ֻ��Ĺ��ܡ�������˽�����ԣ��������͡����롢����״̬��ͣ�����ڣ��������������졢�������졢��ӡ��ͣ����
1���������ͱ�ʾ�û����ֻ�õ�����ĸ��A��ʾ������B��ʾ��ҵ��C��ʾ����
2��������11λ��������һ���ַ�����ʾ
3������״̬��һ�����ֱ�ʾ��1��2��3�ֱ��ʾ���á�δ�á�ͣ��
4��ͣ��������һ�����ڶ���ָ�룬�ڳ�ʼ��ʱ�ó�Աָ��գ������������˽�����������գ��Լ����캯���ʹ�ӡ������
----------------------------------------
5�����캯�������þ��ǽ������������������ø�������ֵ,�������ʾ��Ϣ����ʾ�����
6����������������Ǹ������ж������Ϣ���������ʾ��Ϣ����ʾ�������
      ��һ��ͣ�����ڸ���θ��ƣ�û��ͣ����θ��ƣ����Ѿ�ͣ������θ��ƣ���
7����ӡ�����ǰѶ�����������Զ�����������ʽ��ʾ��
8��ͣ��������ͣ�õ�ǰ���룬������ͣ�����ڣ��޷���ֵ�������ǰ�״̬�ĳ�ͣ�ã���ͣ������ָ�봴��Ϊ��̬���󣬲����ݲ���������ͣ�����ڣ���������ʾ��Ϣ����ʾ�����
-------------------------------------------
Ҫ������������ʵ�ֺ��뱸�ݵĹ��ܣ������е������ֻ��ŵ�������Ϣ���и��ƣ������������͸ĳ�D��ʾ���ݣ����ֻ�����ĩβ����ĸX
����
��һ������t��ʾ��t������

�ڶ�������6�������������������͡����롢״̬��ͣ�����ꡢ�¡��գ��ÿո����

��������t��

���
ÿ��ʾ��������У��������ԭ������Ϣ�����ݺ�����Ϣ��ԭ����ͣ�������Ϣ

ÿ��ʾ��֮���ö̻��ߣ��ĸ����ָ����ʾ�����

��������
2
A 15712345678 1 2015 1 1
B 13287654321 2 2012 12 12
�������
Construct a new phone 15712345678
����=����||����=15712345678||State=����
Construct a copy of phone 15712345678
����=����||����=15712345678X||State=����
Stop the phone 15712345678
����=����||����=15712345678||State=ͣ��||ͣ������=2015.1.1
----
Construct a new phone 13287654321
����=��ҵ||����=13287654321||State=δ��
Construct a copy of phone 13287654321
����=����||����=13287654321X||State=δ��
Stop the phone 13287654321
����=��ҵ||����=13287654321||State=ͣ��||ͣ������=2012.12.12
----*/