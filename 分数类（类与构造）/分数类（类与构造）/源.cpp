#include<iostream>
using namespace std;
class CFraction
{
private:
    int fz, fm;
public:
    CFraction(int fz_val, int fm_val);
    CFraction add(const CFraction& r);
    CFraction sub(const CFraction& r);
    CFraction mul(const CFraction& r);
    CFraction div(const CFraction& r);
    int getGCD();
    void print();
};
CFraction::CFraction(int fz_val, int fm_val)
{
    fz = fz_val;
    fm = fm_val;
}
CFraction CFraction::add(const CFraction& r)
{
    int z, m;
    m = fm * r.fm;
    z = fz*r.fm + r.fz*fm;
    return CFraction(z,m);
}
CFraction CFraction::sub(const CFraction& r)
{
    int z, m;
    m = fm * r.fm;
    z = fz * r.fm - r.fz * fm;
    return CFraction(z, m);
}
CFraction CFraction::mul(const CFraction& r)
{
    int z, m;
    m = fm * r.fm;
    z = fz * r.fz;
    return CFraction(z, m);
}
CFraction CFraction::div(const CFraction& r)
{
    int z, m;
    m = fm * r.fz;
    z = fz * r.fm;
    return CFraction(z, m);
}
int CFraction::getGCD()
{
    int a, b, r,s;
    if (fz > fm)
    {
        a = fz;
        b = fm;
        for (;;)
        {
            r = a % b;
            if (r == 0)
            {
                s = b;
                break;
            }
            else
            {
                a = b;
                b = r;
            }
        }
    }
    else
    {
        a = fm;
        b = fz;
        for (;;)
        {
            r = a % b;
            if (r == 0)
            {
                s = b;
                break;
            }
            else
            {
                a = b;
                b = r;
            }
        }
    }
    return s;
}
void CFraction::print()
{
    int d;
    d= getGCD();
    fz = fz / d;
    fm = fm / d;
    if (fm < 0)
    {
        fz = -fz;
        fm = -fm;
    }
        cout << fz << "/" << fm << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, w, e, r;
        char t, y;
        cin >> q >> t >> w >> e >> y >> r;
        CFraction a(q, w);
        CFraction b(e, r);
        a.add(b).print();
        a.sub(b).print();
        a.mul(b).print();
        a.div(b).print();
        cout << endl;
    }
}/*��Ŀ����
������з������ʵ��:

class CFraction
{
private:
     int fz, fm;
public:
     CFraction(int fz_val, int fm_val) ;
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD();   // �����ķ��Ӻͷ�ĸ�����Լ��
     void print();
};

������a��b�����Լ���ɲ���շת��������ֳ�ŷ������㷨���䲽��Ϊ:

1. ����a, bʹa > b;
2. ��a��b�õ�����r,��r=0,��bΪ���Լ��,�˳�.
3. ��r��Ϊ0,����b����a, r����b,��ʱa,b������һ�ε�С,�����ģ��С��;
4. ������2����

����
�������ݵ����� t

��һ���һ������

��һ��ڶ�������

�ڶ����һ������

�ڶ���ڶ�������

......

���
��һ�����������ĺ�

��һ�����������Ĳ�

��һ�����������Ļ�

��һ��������������

�ڶ������������ĺ�

�ڶ������������Ĳ�

�ڶ������������Ļ�

�ڶ���������������

......

��������
3
1/2
2/3
3/4
5/8
21/23
8/13
�������
7/6
-1/6
1/3
3/4

11/8
1/8
15/32
6/5

457/299
89/299
168/299
273/184
*/