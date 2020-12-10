#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
//------�ඨ��-------
class Point
{
public:
	void SetPoint(int, int);
	int GetX();
	int GetY();
protected:
	int x;
	int y;
};
class Circle
{
public:
	void SetCenter(int, int);
	void SetRadius(int);
	double getArea();
	double getLength();
	void Contain(Point);
protected:
	int x;
	int y;
	int r;
	
	
};
//--------��ʵ��--------
void Point::SetPoint(int m, int n)
{
	x = m;
	y = n;
}
int Point::GetX()
{
	return x;
}
int Point::GetY()
{
	return y;
}
void Circle::SetCenter(int a, int b)
{
	x = a;
	y = b;
}
void Circle::SetRadius(int c)
{
	r = c;
}
double Circle::getArea()
{
	double s;
	s = 3.14 * r * r;
	return s;
}
double Circle::getLength()
{
	double c;
	c = 2 * 3.14 * r;
	return c;
}
void Circle::Contain(Point k)
{
	double d;
	d = sqrt(((k.GetX()) - x)* ((k.GetX()) - x) + ((k.GetY()) - y)* ((k.GetY()) - y));
	if (d > r)
		cout << "no" << endl;
	// if (fabs(d - r) < 0.000001)
	//	cout << "yes" << endl;
	else
		cout << "yes" << endl;
}
//--------������--------
int main()
{
	int m, n, a, b, c;
	Circle h;
	Point k;
	cin >> a >> b >> c >> m >> n;
	k.SetPoint(m, n);
	h.SetCenter(a, b);
	h.SetRadius(c);
	cout << h.getArea() << " " << h.getLength() << endl;
	h.Contain(k);
}
/*��Ŀ����
���һ������Point���������ԣ�x�����y���꣬�������趨���꣨SetPoint������ȡx���꣨GetX������ȡy���꣨GetY��

���һ��Բ��Circle���������ԣ�Բ������x��y���뾶r������������

1. �趨Բ�ģ�SetCenter��������Բ��x�����y����

2. �趨�뾶��SetRadius�������ð뾶����

3. ���������getArea�������㹫ʽ�����=3.14*r*r

4. �����ܳ���getLength�������㹫ʽ���ܳ�=2*3.14*r

5. ������Contain�����ж�һ��Բ�Ƿ����һ���㣬����Բ�ĵ������ľ��룬Ȼ��Ͱ뾶���Ƚϣ������򲻰�����С�ڵ��������

ע�⣺�ύ����ʱ������ע�ͻ��ֳ����������ඨ�塢��ʵ�֡�������������

//-----�ඨ��------

class XXX

{  // д�ඨ�����

};

//----��ʵ��------

void XXX::Process()

{ // д�ඨ�����

};

//-----������-----

int main()

{

  //�Զ���һЩ����

  //����һ��Բ�����һ�������

 //����Բ����͵�����������ֵ��������ʼ��

 //���Բ�������Բ���ܳ�

//���Բ�Ƿ�����㣬���������yes���������no

  return 0;

}

����
��һ������Բ������������Բ�ĵ�x��y���꣬�뾶

�ڶ�������������������x��y����

���
��һ�����Բ��������ܳ������֮���ÿո������������ȵ�С�����2λ

�ڶ������Բ�Ƿ�����㣬���������yes���������no

��C++�У����ָ�����ȵĲο��������£�

#include <iostream>

#include <iomanip> //����������ͷ�ļ�

using namespace std;

void main( )

{ double a =3.14;

  cout<<fixed<<setprecision(3)<<a<<endl;  //���С�����3λ

��������
1 1 1
2 2
�������
3.14 6.28
no
��ʾ
���������Ĺ�ʽ dis =sqrt [ (x1-x2)^2  + (y1-y2)^2 ] �� ^2��ʾƽ����sqrt��ʾ��ƽ����������ʽֻ�Ǳ�ʾ���壬������ʵ����


��C++ʹ��sqrt����������ƽ������ͷ�ļ�����cmath*/