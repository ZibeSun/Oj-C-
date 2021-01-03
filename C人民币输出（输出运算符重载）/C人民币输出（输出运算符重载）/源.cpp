#include<iostream>
using namespace std;
class rmb
{
protected:
	int yuan;
	int jiao;
	int fen;
	int money;
public:
	rmb()
	{
		yuan = 0;
		jiao = 0;
		fen = 0;
	}
	void set(double m)
	{
		m = m * 100;
		money = (int)m;
	}
	void separate()
	{
		yuan = money / 100;
		fen = money % 10;
		jiao = (money % 100 - fen) / 10;
	}
	friend ostream& operator<<(ostream& oo, rmb& a);
};
ostream& operator<<(ostream& oo, rmb& a)
{
	oo << "yuan=" << a.yuan << " " << "jiao=" << a.jiao << " " << "fen=" << a.fen << endl;
	return oo;
}
int main()
{
	int t;
	cin >> t;
	rmb* p = new rmb[t];
	for(int i=0;i<t;i++)
	{
		double m;
		cin >> m;
		p[i].set(m);
		p[i].separate();
		cout << p[i];
	}
	return 0;
}

/*题目描述
定义一个人民币类，包括元、角、分三个非负整数属性，操作包括初始化和输出

初始化用构造函数实现，接收一个浮点数参数（精度为小数点后两位），并转化为元、角、分，例如输入1.23元，经过构造函数转为1元、2角、3分

输出函数对元角分进行输出，具体格式看示例

由于OJ编译器对double强制类型转换成int的处理精度有偏差，建议加一个很小的数(如0.000001)处理(例如数据1.38，由于误差，在内存中的存储值为1.379999）

可以用全局函数重载法（课本介绍的），或者友元方法，两种方法来尝试实现

输入
第一行输入t表示有t个实例

第二行起，输入t个正浮点数，带两位小数，每个数值表示以元为单位的人民币金额

输出
每行输出把浮点数的人民币金额，转化为元角分的整数格式，具体看输出

样例输入
2
2.45
1.38
样例输出
yuan=2 jiao=4 fen=5
yuan=1 jiao=3 fen=8*/