#include<iostream>
using namespace std;
struct birth
{
	int year;
	int month;
	int day;
	int sum;
};
int main()
{
	int t,max, secondmax=0, x=0;
	cin >> t;
	birth sr[100];
	for (int i = 0;i < t;i++)
	{
		cin >> sr[i].year >> sr[i].month >> sr[i].day;
		sr[i].sum = -sr[i].year * 10000 - sr[i].month * 100 - sr[i].day;
	}
	max = sr[0].sum;
	for (int i = 0;i < t;i++)
	{
		if (sr[i].sum > max)
		{
			secondmax = max;
			max = sr[i].sum;
		}
		else
		{
			if (sr[i].sum > secondmax)
			{
				secondmax = sr[i].sum;
				x = i;
			}
		}
	}
	cout<< sr[x].year <<"-"<< sr[x].month <<"-"<< sr[x].day;
}
