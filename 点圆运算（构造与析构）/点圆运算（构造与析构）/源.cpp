#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	/*Point(int n)
	{
		Point *p=new Point[n];
	}*/
	Point(int a,int b)
	{
		x_val = a;
		y_val = b;
	}
	Point()
	{

	}
	~Point()
	{
		x_val = 0;
		y_val = 0;
		cout << "point clear" << endl;
	}
	void setXY(int x, int y)
	{
		x_val = x;
		y_val = y;
	}
	int getX()
	{
		return x_val;
	}
	int getY()
	{
		return y_val;
	}
protected:
	int x_val;
	int y_val;
};
class Circle
{
public:
	Circle(int x,int y,int r)
	{
		x_value = x;
		y_value = y;
		radious = r;
	}
	~Circle()
	{
		x_value = 0;
		y_value = 0;
		radious = 0;
		cout << "circle clear" << endl;
	}
	void Contain(Point &a)
	{
		double d;
		d = sqrt((a.getX() - x_value) * (a.getX() - x_value) + (a.getY() - y_value) * (a.getY() - y_value));
		if (d > radious)
		{
			cout << "out" << endl;
		}
		else
		{
			cout << "in" << endl;
		}
	}
protected:
	int x_value;
	int y_value;
	int radious;
};
int main()
{
	int q, w, n,x,y,r;
	cin >> q >> w;
	Point e(q, w);
	cin >> n;
	Point* p = new Point[n];
	for (int i = 0;i < n;i++)
	{
		int t, y;
		cin >> t >> y;
		p[i].setXY(t, y);
	}
	cin >> x >> y >> r;
	Circle o(x, y, r);
	o.Contain(e);
	for (int i = 0;i < n;i++)
	{
		o.Contain(p[i]);
	}
	return 0;
}/* 题目描述
设计一个点类Point，包含私有属性x坐标和y坐标，操作包括

1、构造函数，要求满足两个条件：1.能够使用类Point去创建一个对象数组（缺省构造方法！）；2.能够接收外来输入的x和坐标做初始化，提示：构造函数重载

2、析构函数，把x坐标和y坐标都清0，并输出信息“point clear”

3、设置(setXY)，接受外来输入，并设置x坐标和y坐标

4、获取x坐标，直接返回x值

5、获取y坐标，直接返回y值

设计一个圆类Circle，包含私有属性：圆心坐标x和y、半径r；操作包括：

1、构造函数，接受外来输入，设置圆心x坐标、y坐标和半径

2、析构函数，将圆心坐标x和y以及半径都清零，并输出"circle clear"

3、包含（Contain），判断一个圆是否包含一个点，计算圆心到这个点的距离，然后和半径做比较，大于则不包含，小于等于则包含。提示：用点对象做参数不一定符合输出

输入
第一行输入一个点的x坐标和y坐标，用Point类去创建一个点对象，并且自动通过构造函数来初始化

第二行输入n，用Point类去创建一个点对象数组，包含n个点

第三行起输入n行，每行输入一个点的x和y坐标，使用设置(setXY)来设置每个点的x和y坐标

接着一行输入三个参数，表示一个圆的圆心坐标x和y，以及半径，使用Circle类去创建一个圆对象，并自动通过构造函数来初始化

输出
通过调用圆的包含(Contain)方法，判断每个点是否在圆内。

按照点的输入顺序，每行输出一个点的判断结果，如果包含则输出in，不包含则输出out

说明：当一个对象数组是动态创建的，那么在程序结束时，这个数组是不会被回收。只有增加代码delete []p，才会回收数组。

本题不要求收回数组.

样例输入
5 2
3
4 7
9 9
2 4
3 3 3
样例输出
in
out
out
in
circle clear
point clear*/ 
