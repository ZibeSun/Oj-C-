#include<iostream>
using namespace std;
class CVehicle
{
protected:
	int max_speed;
	int speed;
	int weight;
public:
	CVehicle()
	{
		max_speed = 0;
		speed = 0;
		weight = 0;
	}
	CVehicle(int ms, int s, int w)
	{
		max_speed = ms;
		speed = s;
		weight = w;
	}
	void display()
	{
		cout << "Vehicle:" << endl;
		cout << "max_speed:" << max_speed << endl;
		cout << "speed:" << speed << endl;
		cout << "weight:" << weight << endl;
		cout << endl;
	}
};
class CBicycle :public CVehicle
{
protected:
	int height;
public:
	CBicycle()
	{
		height = 0;
	}
	CBicycle(int ms, int s, int w, int h)
	{
		CBicycle::max_speed = ms;
		CBicycle::speed = s;
		CBicycle::weight = w;
		height = h;
	}
	void display()
	{
		cout << "Bicycle:" << endl;
		cout << "max_speed:" << CBicycle::max_speed << endl;
		cout << "speed:" << CBicycle::speed << endl;
		cout << "weight:" << CBicycle::weight << endl;
		cout << "height:" << height << endl;
		cout << endl;
	}
};
class CMotocar :public CVehicle
{
protected:
	int seat_num;
public:
	CMotocar()
	{
		seat_num = 0;
	}
	CMotocar(int ms, int s, int w, int sn)
	{
		CMotocar::max_speed = ms;
		CMotocar::speed = s;
		CMotocar::weight = w;
		seat_num = sn;
	}
	void display()
	{
		cout << "Motocar:" << endl;
		cout << "max_speed:" << CMotocar::max_speed << endl;
		cout << "speed:" << CMotocar::speed << endl;
		cout << "weight:" << CMotocar::weight << endl;
		cout << "seat_num:" << seat_num << endl;
		cout << endl;
	}
};
class CMotocycle :public CBicycle, public CMotocar
{
public:
	CMotocycle(int ms, int s, int w, int h,int sn)
	{
		CBicycle::max_speed = ms;
		CBicycle::speed = s;
		CBicycle::weight = w;
		height = h;
		seat_num = sn;
	}
	void display()
	{
		cout << "Motocycle:" << endl;
		cout << "max_speed:" << CBicycle::max_speed << endl;
		cout << "speed:" << CBicycle::speed << endl;
		cout << "weight:" << CBicycle::weight << endl;
		cout << "height:" << height << endl;
		cout << "seat_num:" << seat_num << endl;
	}
};
int main()
{
	int ms, s, w, h, sn;
	cin >> ms >> s >> w >> h >> sn;
	CVehicle a(ms, s, w);
	CBicycle b(ms, s, w, h);
	CMotocar c(ms, s, w, sn);
	CMotocycle d(ms, s, w, h, sn);
	a.display();
	b.display();
	c.display();
	d.display();
	return 0;
}
/*题目描述
1、建立如下的类继承结构：

1)一个车类CVehicle作为基类，具有max_speed、speed、weight等数据成员，display()等成员函数

2)从CVehicle类派生出自行车类CBicycle，添加属性：高度height

3)从CVehicle类派生出汽车类CMotocar，添加属性：座位数seat_num

4)从CBicycle和CMotocar派生出摩托车类CMotocycle

2、分别定义以上类的构造函数、输出函数display及其他函数（如需要）。

3、在主函数中定义各种类的对象，并测试之，通过对象调用display函数产生输出。

输入
第一行：最高速度 速度 重量 第二行：高度 第三行：座位数

输出
第一行：Vehicle: 第二行及以后各行：格式见Sample

样例输入
100 60 20
28
2
样例输出
Vehicle:
max_speed:100
speed:60
weight:20

Bicycle:
max_speed:100
speed:60
weight:20
height:28

Motocar:
max_speed:100
speed:60
weight:20
seat_num:2

Motocycle:
max_speed:100
speed:60
weight:20
height:28
seat_num:2*/