#include<iostream>
using namespace std;
void bj(int p1, int p2, int p3)
{
	int max, h, min;
	if (p1 > p2)
	{
		if (p1 >  p3)
		{
			max = p1;
			if (p2 < p3)
			{
				min = p2;
				h = p3;
			}
			else if (p2 > p3)
			{
				min = p3;
				h = p2;
			}
		}
		else if (p1 < p3)
		{
			max = p3;
			min = p2;

		}
	}
	else if (p1 < p2)
	{
		if (p2 > p3)
		{
			max = p2;
			if (p1 > p3)
			{
				min = p3;
				h = p1;
			}
			else if (p1 < p3)
			{
				min = p1;
				h = p3;
			}
		}
		else if (p2 < p3)
		{
			max = p3;
			min = p1;
			h = p2;
		}
	}
	cout << max << " " << h<< " "<<min << endl;
}
int main()
{
	int t,a,b,c;
	int& p1 = a;
	int& p2 = b;
	int& p3 = c;
	cin >> t;
	while (t--)
	{
		cin >> a
			>> b
			>> c;
		bj(p1, p2, p3);
	}
	return 0;
}
/*��Ŀ����
��������������Ȼ���մӴ�С��˳�������ֵ��

Ҫ�󣺶���һ���������޷���ֵ�����������������������������ã�����int &a, int &b, int &c���ں�����ͨ�����÷������������������������������������������������

Ҫ�󣺲���ֱ�Ӷ����������������򣬱���ͨ���������������õķ�����

����
��һ������t��ʾ��t������ʵ��

�ڶ�����ÿ��������������

����t��

���
ÿ�а��մӴ�С��˳�����ÿ��ʵ������������֮���õ����ո����

��������
3
2 4 6
88 99 77
111 333 222
�������
6 4 2
99 88 77
333 222 111*/