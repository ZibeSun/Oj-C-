#include<iostream>
using namespace std;
class Animal
{
protected:
	string name;
	int age;
public:
	Animal()
	{
		age = 0;
	}
	Animal(string n, int ag)
	{
		name = n;
		age = ag;
	}
	virtual void Speak() = 0;
};
class Tiger :public Animal
{
public:
	Tiger(string n, int ag) :Animal(n, ag)
	{

	}
	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",AOOO." << endl;
	}
};
class Pig :public Animal
{
public:
	Pig(string n, int ag) :Animal(n, ag)
	{

	}
	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",HENGHENG." << endl;
	}
};
class Duck :public Animal
{
public:
	Duck(string n, int ag) :Animal(n, ag)
	{

	}
	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",GAGA." << endl;
	}
};
class Dog :public Animal
{
public:
	Dog(string n, int ag) :Animal(n, ag)
	{

	}
	virtual void Speak()
	{
		cout << "Hello,I am " << name << ",WangWang." << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string ani, n;
		Animal* p;
		int ag;
		cin >> ani >> n >> ag;
		if (ani == "Tiger")
		{
			p = new Tiger(n, ag);
		}
		else if (ani == "Pig")
		{
			p = new Pig(n, ag);
		}
		else if (ani == "Duck")
		{
			p = new Duck(n, ag);
		}
		else if (ani == "Dog")
		{
			p = new Dog(n, ag);
		}
		else
			cout << "There is no " << ani << " in our Zoo." << endl;
		p->Speak();
	}
	return 0;
}/*��Ŀ����
ĳ������԰�ڣ����ϻ�������Ѽ�Ӻ���ȶ������԰�Ĺ���ԱΪÿ�����ﶼ����һ�����֣�����ÿ�����ﶼ�����䡢���ص���Ϣ��ÿ��ιʳ��ʱ�򣬲�ͬ�Ķ��ﶼ��л�(speak)��ÿ�ֶ���Ľл�������ͬ���ϻ��Ľл����ǡ�AOOO�������Ľл����ǡ�WangWang����Ѽ�ӵĽл����ǡ�GAGA������Ľл����ǡ�HENGHENG����

����һ��Animal�Ļ��࣬Animal���к���Speak()���������ϻ�������Ѽ�Ӻ����࣬���ܷ�����ͬ�Ľл��������ı���Ϣ�����������

��д�������붯�����ơ����֡����䣬�ö���԰�ڵĸ��ֶ���л���

Ҫ��ֻʹ��һ������ָ�룬ָ�����ɵĶ��󲢵��÷�����

����
���԰����ĸ���

��һ�ֶ��������  ����  ����

�ڶ��ֶ��������  ���� ����

......

���
�����Ӧ�������Ϣ

��������ڸ��ֶ�����There is no �������� in our Zoo.  ����������ο��������

��������
4
Tiger Jumpjump 10
Pig Piglet 4
Rabbit labi 3
Duck tanglaoya 8
�������
Hello,I am Jumpjump,AOOO.
Hello,I am Piglet,HENGHENG.
There is no Rabbit in our Zoo.
Hello,I am tanglaoya,GAGA.*/