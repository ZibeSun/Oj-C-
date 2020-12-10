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
}/*题目描述
编写一个程序，定义抽象基类Shape，在Shape类中定义虚函数Area()；由它派生出3个派生类：Circle(圆形)、Square(正方形)、Rectangle(矩形)。用虚函数分别计算几种图形面积。
1、要求输出结果保留两位小数。
2、要求用基类指针数组，使它每一个元素指向每一个派生类对象。
输入
测试数据的组数 t

第一组测试数据中圆的半径

第一组测测试数据中正方形的边长

第一组测试数据中矩形的长、宽

.......

第 t 组测试数据中圆的半径

第 t 组测测试数据中正方形的边长

第 t 组测试数据中矩形的长、宽

输出
第一组数据中圆的面积

第一组数据中正方形的面积

第一组数据中矩形的面积

......

第 t 组数据中圆的面积

第 t 组数据中正方形的面积

第 t 组数据中矩形的面积

样例输入
2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12
样例输出
4.52
5.29
2.76
13.85
10.24
2.61*/