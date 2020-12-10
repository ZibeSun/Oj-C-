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
}/*题目描述
完成下列分数类的实现:

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
     int getGCD();   // 求对象的分子和分母的最大公约数
     void print();
};

求两数a、b的最大公约数可采用辗转相除法，又称欧几里得算法，其步骤为:

1. 交换a, b使a > b;
2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
4. 继续第2步。

输入
测试数据的组数 t

第一组第一个分数

第一组第二个分数

第二组第一个分数

第二组第二个分数

......

输出
第一组两个分数的和

第一组两个分数的差

第一组两个分数的积

第一组两个分数的商

第二组两个分数的和

第二组两个分数的差

第二组两个分数的积

第二组两个分数的商

......

样例输入
3
1/2
2/3
3/4
5/8
21/23
8/13
样例输出
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