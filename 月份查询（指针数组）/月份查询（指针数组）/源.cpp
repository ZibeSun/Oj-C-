#include<iostream>
using namespace std;
int main()
{
	int t,n;
	const char* month[ ] = { "January","February","March","April","May","June","July","Aguest","September","October","November","December" };
	cin >> t;
	while (t--)
	{
		cin >> n;
		if ((1 <= n) && (n <= 12))
			cout << month[n - 1] << endl;
		else if (n > 12)
			cout << "error" << endl;
		else if (n < 1)
			cout << "error" << endl;
	}
	return 0;
}
/*��Ŀ����
��֪ÿ���·ݵ�Ӣ�ĵ������£�Ҫ�󴴽�һ��ָ�����飬�����е�ÿ��ָ��ָ��һ���·ݵ�Ӣ���ַ�����Ҫ�����������·����������Ӧ��Ӣ�ĵ���
1�� January 
2�� February
3�� March
4�� April
5�� May
6�� June
7�� July
8�� Aguest
9�� September
10�� October
11�� November
12�� December
����
��һ������t��ʾt������ʵ��

����ÿ������һ���·ݵ�����

��������t��

���
ÿ�������Ӧ���·ݵ��ַ�������û������·ݵĵ��ʣ����error

��������
3
5
11
15
�������
May
November
error*/