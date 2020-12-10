#include<iostream>
#include<iomanip>
using namespace std;
double pai=3.1415;
class Shape
{
public:
	virtual void Area() = 0;
};
class Circle :public Shape
{
protected:
	double Radius;
public:
	Circle(double r)
	{
		Radius = r;
	}
	virtual void Area()
	{
		double sum;
		sum = pai * Radius * Radius;
		cout << fixed << setprecision(2) << sum << endl;
	}
};
class Square :public Shape
{
protected:
	double Side;
public:
	Square(double s)
	{
		Side = s;
	}
	virtual void Area()
	{
		double sum;
		sum = Side * Side;
		cout << fixed << setprecision(2) << sum << endl;
	}
};
class Rectangle :public Shape
{
protected:
	double LongSide;
	double ShortSide;
public:
	Rectangle(double ls, double ss)
	{
		LongSide = ls;
		ShortSide = ss;
	}
	virtual void Area()
	{
		double sum;
		sum = LongSide * ShortSide;
		cout << fixed << setprecision(2) << sum << endl;
	}
};
void fn(Shape* p)
{
	p->Area();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Shape* p[3];
		double r, s, ls, ss;
		cin >> r >> s >> ls >> ss;
		Circle a(r);
		Square b(s);
		Rectangle c(ls, ss);
		p[0] = &a;
		p[1] = &b;
		p[2] = &c;
		fn(p[0]);
		fn(p[1]);
		fn(p[2]);
	}
	return 0;
}/*��Ŀ����
��дһ�����򣬶���������Shape����Shape���ж����麯��Area()������������3�������ࣺCircle(Բ��)��Square(������)��Rectangle(����)�����麯���ֱ���㼸��ͼ�������
1��Ҫ��������������λС����
2��Ҫ���û���ָ�����飬ʹ��ÿһ��Ԫ��ָ��ÿһ�����������
����
�������ݵ����� t

��һ�����������Բ�İ뾶

��һ�����������������εı߳�

��һ����������о��εĳ�����

.......

�� t �����������Բ�İ뾶

�� t �����������������εı߳�

�� t ����������о��εĳ�����

���
��һ��������Բ�����

��һ�������������ε����

��һ�������о��ε����

......

�� t ��������Բ�����

�� t �������������ε����

�� t �������о��ε����

��������
2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12
�������
4.52
5.29
2.76
13.85
10.24
2.61*/