#include<iostream>
#include<string.h>
using namespace std;
struct paper
{
	int number;
	char answer1[999];
	char answer2[999];
	char answer3[999];
};
int bj(char h[999], char k[999])
{
	int a, b, x = 0;
	a = strlen(h);
	b = strlen(k);
	if (a <= b)
	{
		for (int i = 0; i < a; i++)
		{
			if (h[i] == k[i])
				x++;
		}
		if (x>=0.9*a)
			return 1;
		else
			return 0;
	}
	else if (a > b)
	{
		for (int i = 0; i < b; i++)
		{
			if (h[i] == k[i])
				x++;
		}
		if (x>=0.9*a)
			return 1;
		else
			return 0;
	}
}
int compare(paper h, paper k)
{
	if (bj(h.answer1, k.answer1) == 1)
		return 1;
	if (bj(h.answer2, k.answer2) == 1)
		return 2;
	if (bj(h.answer3, k.answer3) == 1)
		return 3;
	return 0;
}
int main()
{
	int t;
	cin >> t;
	paper student[100];
	for (int i = 0; i < t; i++)
	{
		cin >> student[i].number >> student[i].answer1 >> student[i].answer2 >> student[i].answer3;
	}
	/*paper* pr[100];
	for (int i = 0; i < t; i++)
	{
		pr[i] = &student[i];
	}*/
	for (int i = 0; i < t; i++)
	{
		for (int k = 0; k < t; k++)
		{
			if (compare(student[i], student[k]) > 0)
			{
				if (i < k)
				{
					cout << student[i].number << " " << student[k].number << " " << compare(student[i], student[k]) << endl;
				}

			}
		}
	}
	return 0;
}