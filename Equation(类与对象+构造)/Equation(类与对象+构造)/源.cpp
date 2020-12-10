#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
class Equation
{
    double a, b, c;
public:
    Equation();
    void set(double z, double x, double y);
    void getRoot();
};
Equation::Equation()
{
    a = 1;
    b = 1;
    c = 0;
}
void Equation::set(double z, double x, double y)
{
    a = z;
    b = x;
    c = y;
}
void Equation::getRoot()
{
    double x1, x2,p,q,s;
    s = b * b - 4 * a * c;
    /*if (s == 0)
    {
        x1 = (-b + sqrt(fabs(s))) / (2 * a);
        cout << fixed << setprecision(2) << "x1=x2=" << x1 << endl;
    }*/
    if (s> 0)
    {
        x1= (-b + sqrt(s)) / (2 * a);
        x2= (-b - sqrt(s)) / (2 * a);
        cout << fixed << setprecision(2) << "x1=" << x1 << " x2=" << x2 << endl;
    }
    else if (s < 0)
    {
        p = (-b) / (2 * a);
        q = sqrt(-s) / (2 * a);
        cout << fixed << setprecision(2) << "x1=" << p << "+" << q << "i " << "x2=" << p << "-" << q << "i" << endl;
    }
    else
    {
        x1 = (-b + sqrt(fabs(s))) / (2 * a);
        cout << fixed << setprecision(2) << "x1=x2=" << x1 << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, w, e;
        Equation h;
        cin >> q >> w >> e;
        h.set(q, w, e);
        h.getRoot();
    }
    return 0;
}/*��Ŀ����
����һ����Equation����﷽��ax2+bx+c=0���������ٰ������·�����

1���޲ι��죨abcĬ��ֵΪ1��1��0�����вι��캯�������ڳ�ʼ��a��b��c��ֵ��

2��set�����������޸�a��b��c��ֵ

3��getRoot������������̵ĸ���

һԪ���η��̵������ʽ���£�



һԪ���η��̵�����������������£�



����
����������ݵ�����t

��һ��a��b��c

�ڶ���a��b��c

���
������̵ĸ��������С�����2λ

��C++�У����ָ�����ȵĲο��������£�

#include <iostream>

#include <iomanip> //����������ͷ�ļ�

using namespace std;

void main( )

{ double a =3.141596;

  cout<<fixed<<setprecision(3)<<a<<endl;  //���С�����3λ

��

��������
3
2 4 2
2 2 2
2 8 2
�������
x1=x2=-1.00
x1=-0.50+0.87i x2=-0.50-0.87i
x1=-0.27 x2=-3.73*/