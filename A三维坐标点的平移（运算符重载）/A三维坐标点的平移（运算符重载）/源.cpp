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
/*题目描述
定义一个三维点Point类，利用友元函数重载"++"和"--"运算符，并区分这两种运算符的前置和后置运算。



要求如下：
1.实现Point类；
2.编写main函数，初始化1个Point对象，将这个对象++或--后赋给另外一个对象，并输出计算后对象的坐标信息。
输入
第1行：输入三个int类型的值，分别为一个Point对象p1的x,y,z坐标。

输出
第1行：Point对象p1后置++之后的坐标信息输出。
第2行：Point对象p1后置++操作后赋给另外一个Point对象p2的坐标信息。
第3行开始，依次输出前置++，后置--，前置--运算的坐标信息，输出格式与后置++一样。
样例输入
10 20 30
样例输出
x=11 y=21 z=31
x=10 y=20 z=30
x=11 y=21 z=31
x=11 y=21 z=31
x=9 y=19 z=29
x=10 y=20 z=30
x=9 y=19 z=29
x=9 y=19 z=29
提示
原值是最初输入的数值


第1行是p1后置++后，再输出


第2行是p1恢复原值，接着p1后置++同时复制给p2，p2输出

第3、4行是p1恢复原值，p1前置++同时输出，然后p1再输出

第5、6行是p1恢复原值，p1后置--后，再输出，接着输出一次原值

第7、8行是p1恢复原值，p1前置--同时输出，然后p1再输出*/