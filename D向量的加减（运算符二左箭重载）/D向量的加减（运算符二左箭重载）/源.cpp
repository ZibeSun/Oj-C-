#include<iostream>
using namespace std;
class Vector
{
protected:
	int vec[10];
public:
	Vector(int v[10])
	{
		for (int i = 0; i < 10; i++)
		{
			vec[i] = v[i];
		}
	}
	Vector()
	{
		for (int i = 0; i < 10; i++)
		{
			vec[i] = 0;
		}
	}
	friend Vector operator+(Vector& a, Vector &b);
	friend Vector operator-(Vector& a, Vector& b);
	friend ostream& operator<<(ostream& out, Vector& a);
};
Vector operator+(Vector& a, Vector& b)
{
	Vector s;
	for (int i = 0; i < 10; i++)
	{
		s.vec[i] = a.vec[i] + b.vec[i];
	}
	return s;
}
Vector operator-(Vector& a, Vector& b)
{
	Vector s;
	for (int i = 0; i < 10; i++)
	{
		s.vec[i] = a.vec[i] - b.vec[i];
	}
	return s;
}
ostream& operator<<(ostream& out, Vector& a)
{
	for (int i = 0; i < 10; i++)
	{
		out << a.vec[i] << " ";
	}
	out << endl;
	return out;
}
int main()
{
	int v1[10], v2[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> v1[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> v2[i];
	}
	Vector a(v1);
	Vector b(v2);
	Vector c;
	Vector d;
	c = a + b;
	d = a - b;
	cout << c << d;
	return 0;
}
/*��Ŀ����
������X=(x1,x2,��,xn)��Y=(y1,y2��,yn),����֮��ļӡ����ֱ���Ϊ��
  X+Y=(x1+y1,x2+y2,��,xn+yn)
  X-Y=(x1-y1,x2-y2,��,xn-yn)
�������������Vector ,�����������+������-��,ʵ������֮��ļӡ�������;�������������<<����Ϊ���������������
Vector��Ļ�����ʽ���£�

Ҫ�����£�
1.ʵ��Vector�ࣻ
2.��дmain��������ʼ������Vector����ģ���������֮��ļӼ�������������
����
��1�У�����10��int���͵�ֵ����ʼ����һ��Vector����
��2��: ����10��int���͵�ֵ����ʼ����һ��Vector����
���
��1�У�2��Vector������Ӻ����������
��2�У�2��Vector������������������
��������
-4 1 0 10 5 -9 8 13 6 2
-11 8 10 17 -6 9 6 7 12 5
�������
-15 9 10 27 -1 0 14 20 18 7
7 -7 -10 -7 11 -18 2 6 -6 -3*/