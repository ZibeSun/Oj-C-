#include<iostream>
using namespace std;
class Point
{
protected:
	int x;
	int y;
	int z;
public:
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point(Point& p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}
	void set(int X, int Y, int Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	friend Point operator ++(Point& a);
	friend Point operator ++(Point& a, int b);
	friend Point operator --(Point& a);
	friend Point operator --(Point& a, int b);
	void show()
	{
		cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
	}
};
Point operator ++(Point& a)
{
	++a.x;
	++a.y;
	++a.z;
	return a;
}
Point operator ++(Point& a, int)
{
	a.x++;
	a.y++;
	a.z++;
	return a;
}
Point operator --(Point& a)
{
	--a.x;
	--a.y;
	--a.z;
	return a;
}
Point operator --(Point& a, int)
{
	a.x--;
	a.y--;
	a.z--;
	return a;
}
int main()
{
	int X, Y, Z;
	cin >> X >> Y >> Z;
	Point a;
	a.set(X, Y, Z);
	a++;
	a.show();
	a.set(X, Y, Z);
	a.show();
	a++;
	Point b(a);
	b.show();
	a.set(X, Y, Z);
	++a;
	a.show();
	a.set(X, Y, Z);
	a--;
	a.show();
	a.set(X, Y, Z);
	a.show();
	--a;
	a.show();
	a.show();
	return 0;
}
/*��Ŀ����
����һ����ά��Point�࣬������Ԫ��������"++"��"--"��������������������������ǰ�úͺ������㡣



Ҫ�����£�
1.ʵ��Point�ࣻ
2.��дmain��������ʼ��1��Point���󣬽��������++��--�󸳸�����һ�����󣬲�������������������Ϣ��
����
��1�У���������int���͵�ֵ���ֱ�Ϊһ��Point����p1��x,y,z���ꡣ

���
��1�У�Point����p1����++֮���������Ϣ�����
��2�У�Point����p1����++�����󸳸�����һ��Point����p2��������Ϣ��
��3�п�ʼ���������ǰ��++������--��ǰ��--�����������Ϣ�������ʽ�����++һ����
��������
10 20 30
�������
x=11 y=21 z=31
x=10 y=20 z=30
x=11 y=21 z=31
x=11 y=21 z=31
x=9 y=19 z=29
x=10 y=20 z=30
x=9 y=19 z=29
x=9 y=19 z=29
��ʾ
ԭֵ������������ֵ


��1����p1����++�������


��2����p1�ָ�ԭֵ������p1����++ͬʱ���Ƹ�p2��p2���

��3��4����p1�ָ�ԭֵ��p1ǰ��++ͬʱ�����Ȼ��p1�����

��5��6����p1�ָ�ԭֵ��p1����--����������������һ��ԭֵ

��7��8����p1�ָ�ԭֵ��p1ǰ��--ͬʱ�����Ȼ��p1�����*/