#include<iostream>
#include<math.h>
using namespace std;
class C2D
{
public:
	double getDistance(double x,double y)
	{
		double d;
		d = sqrt(x * x + y * y);
		return d;
	}
	
};
class C3D :public C2D
{
public:
	double getDistance(double x, double y,double z)
	{
		double d;
		d = sqrt(x * x + y * y+z*z);
		return d;
	}
};
int main()
{
	double x1, y1, x2, y2, z2, x3, y3, z3;
	cin >> x1 >> y1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
	C2D a;
	C3D b;
	C3D c;
	cout << a.getDistance(x1, y1) << endl << b.getDistance(x2, y2, z2) << endl << c.getDistance(x3, y3, z3) << endl << a.getDistance(x3, y3) << endl;
	return 0;
}
/*��Ŀ����
����һ��ƽ���ϵĵ�C2D�࣬������һ��getDistance()�ĳ�Ա����������õ㵽ԭ��ľ��룻��C2D����������ά�ռ�ĵ�C3D�࣬����getDistance()��Ա��������õ㵽ԭ��ľ��롣�Էֱ�����һ��C2D��C3D�Ķ��󣬼������ǵ�ԭ��ľ��롣
��ά�ռ�����㣨x, y, z���ͣ�x1, y1, z1���ľ��빫ʽ���£�
[(x-x1)^2+(y-y1)^2+(z-z1)^2]^(1/2) 
����
��һ�ж�ά�����λ��

�ڶ�����ά�����λ��1

��������ά�����λ��2

���
��һ�ж�ά�����λ�õ�ԭ��ľ���

�ڶ�����ά�����λ��1��ԭ��ľ���

��������ά�����λ��2��ԭ��ľ���

��������ά�����λ��2��ֵ����ά���������󣬶�ά����㵽ԭ��ľ���

��������
3 4
3 4 5
6 8 8
�������
5
7.07107
12.8062
10*/