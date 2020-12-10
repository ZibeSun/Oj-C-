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
/*��Ŀ����
1���������µ���̳нṹ��

1)һ������CVehicle��Ϊ���࣬����max_speed��speed��weight�����ݳ�Ա��display()�ȳ�Ա����

2)��CVehicle�����������г���CBicycle��������ԣ��߶�height

3)��CVehicle��������������CMotocar��������ԣ���λ��seat_num

4)��CBicycle��CMotocar������Ħ�г���CMotocycle

2���ֱ���������Ĺ��캯�����������display����������������Ҫ����

3�����������ж��������Ķ��󣬲�����֮��ͨ���������display�������������

����
��һ�У�����ٶ� �ٶ� ���� �ڶ��У��߶� �����У���λ��

���
��һ�У�Vehicle: �ڶ��м��Ժ���У���ʽ��Sample

��������
100 60 20
28
2
�������
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