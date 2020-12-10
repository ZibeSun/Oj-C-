#include<iostream>
using namespace std;
class Count
{
public:
	void set(int a,int b,int c,int d)
	{
		id = a;
		phone = b;
		key = c;
		money = d;
	}
	int find(int j)
	{
		if (j != phone)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int password(int k)
	{
		if (k != key)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	void getmoney(int l)
	{
		if (l > money)
		{
			cout << "卡号" << id << "--余额不足" << endl;
		}
		else
		{
			money = money - l;
			cout << "卡号" << id << "--余额" << money << endl;
		}
	}
protected:
	int id;
	int phone;
	int key;
	int money;
};
int main()
{
	int n,k;
	cin >> n;
	Count *p = new Count[n];
	for (int i=0;i < n;i++)
	{
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		p[i].set(q, w, e, r);
	}
	cin >> k;
	while (k--)
	{
		int a, s, d,x=0;
		cin >> a >> s >> d;
		for (int i=0;i < n;i++)
		{
			if (p[i].find(a) == 0)
			{
				x++;
			}
			else
			{
				if (p[i].password(s) == 0)
				{
					cout << "密码错误" << endl;
				}
				else
				{
					p[i].getmoney(d);
				}
			}
		}
		if (x == n)
		{
			cout << "手机号不存在" << endl;
		}
	}
	return 0;
}/*题目描述
采用面向对象思想实现手机取款的过程
假设银行账户有卡号、绑定手机号、动态密码、余额等属性，包含获取各种属性、校验动态密码、取款操作。属性全是整数数据。
使用对象数组来保存n个银行账户。
用户通过手机取款的步骤如下：(一般在主函数实现)
1、用户输入手机号，在n个银行账户中找到相应的银行账户。
	如果查找成功则往下执行，否则输出信息“手机号不存在”，不再往下执行；
2、用户输入动态密码，然后校验动态密码的是否正确
	如果密码正确则往下执行，否则输出信息“密码错误”，不再往下执行；
3、用户输入取款金额，然后执行取款操作
	如果余额不足就拒绝取款并给出信息“卡号XXX--余额不足”；如果取款成功给出信息“卡号XXX--余额YYY”，其中XXX表示卡号，YYY表示余额
上述描述只是方便说明，可以一次输入所有数据再执行各个操作。
输入
第一行输入n，表示有n个账户
下一行输入第一个账户的信息：卡号、绑定手机号、动态密码、余额
连续输入n行
接着输入k，表示要执行k次取款操作
下一行输入手机号、动态密码、取款金额
连续输入k行
输出
输出k行，每行输出操作结果

样例输入
5
1001 138111 111 1000
1002 135222 222 200
1003 136333 333 300
1004 133444 444 400
1005 132555 555 500
4
136333 333 600
133444 444 300
133555 555 200
138111 222 900
样例输出
卡号1003--余额不足
卡号1004--余额100
手机号不存在
密码错误*/ 
