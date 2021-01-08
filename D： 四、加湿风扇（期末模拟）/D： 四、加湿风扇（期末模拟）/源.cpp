#include<iostream>
using namespace std;
class HomeMachine
{
protected:
	int number;
	int power;
public:
	HomeMachine()
	{

	}
	HomeMachine(int in_number,int in_power)
	{
		number = in_number;
		power = in_power;
	}
	virtual void printf()
	{

	}
};
class Fan :virtual public HomeMachine
{
protected:
	int wind_direction;
	int wind_level;
public:
	Fan(int wd, int wl)
	{
		wind_direction = wd;
		wind_level = wl;
	}
	void wdcontrol(int wd)
	{
		wind_direction = wd;
	}
	void wlcontrol(int wl)
	{
		wind_level = wl;
	}
};
class Humidifier :virtual public HomeMachine
{
protected:
	float actual_water;
	float max_water;
public:
	Humidifier(int aw, int mw)
	{
		actual_water = aw;
		max_water = mw;
	}
	int warning()
	{
		if (actual_water >= (max_water / 2))
			return 1;
		else if ((actual_water < (max_water / 2)) && (actual_water >= (max_water / 10)))
			return 2;
		else
			return 3;
	}
};
class HumidifierFan :public Fan, public Humidifier
{
protected:
	int mode;
public:
	HumidifierFan(int in_number, int in_power, int wd, int wl, int aw, int mw, int m) : HomeMachine(in_number, in_power), Fan(wd, wl), Humidifier(aw, mw)
	{
		mode = m;
	}
	void modecontrol(int m)
	{
		if (m == 1)
		{
			wdcontrol(0);
			wlcontrol(1);
			mode = m;
		}
		else if (m == 2)
		{
			wdcontrol(1);
			wlcontrol(2);
			mode = m;
		}
		else if (m == 3)
		{
			wdcontrol(1);
			wlcontrol(3);
			mode = m;
		}
	}
	virtual void printf()
	{
		cout << "加湿风扇--档位" << mode << endl << "编号" << number << "--功率" << power << "W" << endl;
		if (wind_direction == 0)
			cout << "定向吹风--";
		else
			cout << "旋转吹风--";
		cout << "风力" << wind_level << "级" << endl;
		cout << "实际水容量" << actual_water << "升--";
		if (warning() == 1)
			cout << "水量正常" << endl;
		else if(warning() == 2)
			cout << "水量偏低" << endl;
		else if (warning() == 3)
			cout << "水量不足" << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, p, wd, wl, aw, mw, m;
		int c_m;
		cin >> n >> p >> wd >> wl >> aw >> mw >> m >> c_m;
		HumidifierFan a(n, p, wd, wl, aw, mw, m);
		a.modecontrol(c_m);
		a.printf();
	}
	return 0;
}
/*题目描述
已知家电有编号、功率的属性，属性都是整数，操作包括构造和打印等

电风扇继承家电的特点，新增两个属性（整数）：风向和风力，其中风向为0表示定向吹风，状态为1表示旋转吹风。
风扇包含两个新操作：风向控制和风力控制
1、风向控制含一个整数参数，无返回，把风向设置为参数值，参数为0表示定向吹风，为1表示旋转吹风。
2、风力控制含一个整数参数，无返回，把风力设置为参数值，参数表示风力级别，例如1级、2级、3级等。
加湿器继承家电的特点，新增两个属性（浮点数）：实际水容量和最大水容量
新增操作是预警，无参数，返回值为整数，当实际水容量不小于最大水容量的50%，则返回1；小于50%且不小于10%则返回2，小于10%则返回3
加湿风扇继承了风扇和加湿器的特点，新增属性档位（整数）
新增操作调整档位，含一个参数，无返回值，先设置档位为参数值，再调用风向控制和风力控制来设置相关属性，包括：
1、参数为0，不做其他属性修改
2、参数为1，设置定向吹风且风力1级
3、参数为2，设置旋转吹风且风力2级
4、参数为3，设置旋转吹风且风力3级
档位只可能是0、1、2、3四个数值，其他数值忽略。
加湿风扇重载打印操作，输出格式参考样本。输出要求如下：
1、如果风向为0，则输出定向吹风，风向为1则输出旋转吹风。
2、调用预警操作，并根据返回结果1、2、3输出不同信息，分别是：水量正常、水量偏低、水量不足
程序要求
1、采用虚拟继承机制实现上述电器的关系，明确谁是虚基类、基类、派生类
2、基类和派生类的构造要考虑虚基类、基类的属性构造
上述所有类属性都不是public，用面向对象思想和C++语言实现上述要求
输入
第一行输入t，表示有t个实例
第二行输入一个加湿风扇的信息，依次包括编号、功率、风向、风力、实际水容量、最大水容量 档位
第三行输入一个参数，表示调档操作的档位，然后执行调档操作。
以此类推，输入t个实例
输出
对于每个实例，调用打印操作输出加湿风扇的最终状态

样例输入
3
1001 1000 1 2 3 4 0
1
2002 2000 0 1 1 12 0
3
3003 3000 0 3 2 10 0
0
样例输出
加湿风扇--档位1
编号1001--功率1000W
定向吹风--风力1级
实际水容量3升--水量正常
加湿风扇--档位3
编号2002--功率2000W
旋转吹风--风力3级
实际水容量1升--水量不足
加湿风扇--档位0
编号3003--功率3000W
定向吹风--风力3级
实际水容量2升--水量偏低*/