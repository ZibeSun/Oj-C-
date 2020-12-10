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
}/* ��Ŀ����
���һ������Point������˽������x�����y���꣬��������

1�����캯����Ҫ����������������1.�ܹ�ʹ����Pointȥ����һ���������飨ȱʡ���췽��������2.�ܹ��������������x����������ʼ������ʾ�����캯������

2��������������x�����y���궼��0���������Ϣ��point clear��

3������(setXY)�������������룬������x�����y����

4����ȡx���ֱ꣬�ӷ���xֵ

5����ȡy���ֱ꣬�ӷ���yֵ

���һ��Բ��Circle������˽�����ԣ�Բ������x��y���뾶r������������

1�����캯���������������룬����Բ��x���ꡢy����Ͱ뾶

2��������������Բ������x��y�Լ��뾶�����㣬�����"circle clear"

3��������Contain�����ж�һ��Բ�Ƿ����һ���㣬����Բ�ĵ������ľ��룬Ȼ��Ͱ뾶���Ƚϣ������򲻰�����С�ڵ������������ʾ���õ������������һ���������

����
��һ������һ�����x�����y���꣬��Point��ȥ����һ������󣬲����Զ�ͨ�����캯������ʼ��

�ڶ�������n����Point��ȥ����һ����������飬����n����

������������n�У�ÿ������һ�����x��y���꣬ʹ������(setXY)������ÿ�����x��y����

����һ������������������ʾһ��Բ��Բ������x��y���Լ��뾶��ʹ��Circle��ȥ����һ��Բ���󣬲��Զ�ͨ�����캯������ʼ��

���
ͨ������Բ�İ���(Contain)�������ж�ÿ�����Ƿ���Բ�ڡ�

���յ������˳��ÿ�����һ������жϽ����������������in�������������out

˵������һ�����������Ƕ�̬�����ģ���ô�ڳ������ʱ����������ǲ��ᱻ���ա�ֻ�����Ӵ���delete []p���Ż�������顣

���ⲻҪ���ջ�����.

��������
5 2
3
4 7
9 9
2 4
3 3 3
�������
in
out
out
in
circle clear
point clear*/ 
