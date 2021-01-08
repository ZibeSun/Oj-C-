#include<iostream>
using namespace std;
class Metal
{
protected:
	int hardness;
	int weight;
	int volume;
public:
	Metal()
	{
		hardness = 0;
		weight = 0;
		volume = 0;
	}
	Metal(int h,int w,int v)
	{
		hardness = h;
		weight = w;
		volume = v;
	}
	friend Metal operator+(Metal& a, Metal& b);  //合并
	friend Metal operator*(Metal& a, int b);     //巨化
	friend Metal operator++(Metal& a);           //硬化，前增量
	friend Metal operator--(Metal& a, int);      //软化，后增量
	void printf()
	{
		cout << "硬度" << hardness << "--重量" << weight << "--体积" << volume << endl;
	}
};
Metal operator+(Metal& a, Metal& b)
{
	Metal sum;
	sum.hardness = a.hardness + b.hardness;
	sum.volume = a.volume + b.volume;
	sum.weight = a.weight + b.weight;
	return sum;
}
Metal operator*(Metal& a, int b)
{
	Metal sum; 
	sum.hardness = a.hardness;
	sum.volume = a.volume * b;
	sum.weight = a.weight;
	return sum;
}
Metal operator++(Metal& a)
{
	++a.hardness;
	a.volume = a.volume * 1.1;
	a.weight = a.weight * 1.1;
	return a;
}
Metal operator--(Metal& a, int)
{
	a.hardness--;
	a.volume = a.volume * 0.9;
	a.weight = a.weight * 0.9;
	return a;
}
int main()
{
	int h1, w1, v1, h2, w2, v2, n;
	cin >> h1 >> w1 >> v1 >> h2 >> w2 >> v2 >> n;
	Metal a(h1, w1, v1);
	Metal b(h2, w2, v2);
	(a + b).printf();
	(a * n).printf();
	(++a).printf();
	(b--).printf();
	return 0;
}
/*题目描述
在金属加工中，金属具有硬度、重量、体积的属性（都是整数），包括四种操作：
1、合并，每两块金属可以合并成一块新的金属。新金属的重量等于原两块金属的重量之和，体积和硬度也类似计算。
2、巨化，金属通过熔炼风吹的方法会巨化，体积变大n倍，重量和硬度不变
3、硬化，在金属中加入高分子材料可以硬化金属，每提升硬度一级，重量和体积都增加10%。
4、软化，在金属中加入特殊化学溶液可以降低金属硬度，每降低硬度一级，重量和体积都减少10%
用类来描述金属，用运算符重载方式实现金属的四种操作，并定义打印函数，具体要求如下
1、用加法运算符、友元的方式实现合并
2、用乘法运算符、友元的方式实现巨化，含两个参数：金属对象、巨化倍数
3、用++运算符、成员函数、前增量的方式实现硬化
4、用--运算符、成员函数、后增量的方式实现软化
5、打印函数用来输出金属的信息，输出格式看参考样本
  

操作中所有属性的运算结果都只保留整数部分。

上述所有类属性都不是public，用面向对象思想和C++语言实现上述要求

输入
第一行输入第一块金属的信息，包括硬度、重量、体积

第二行输入第二块金属的信息，包括硬度、重量、体积

第三行输入一个参数n，表示巨化n倍

输出
第一行输出两块金属合并后的信息

第二行输出第一块金属巨化n倍的信息

第三行输出第一块金属提升硬度一级后的信息

第四行输出第二块金属降低硬度一级后的信息

样例输入
3 3000 300
5 5000 500
2
样例输出
硬度8--重量8000--体积800
硬度3--重量3000--体积600
硬度4--重量3300--体积330
硬度4--重量4500--体积450*/