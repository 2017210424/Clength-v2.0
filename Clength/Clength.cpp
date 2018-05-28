// Clength.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
class CLength
{
private:
	int feet;
	double inch;
public:
	CLength()
	{
		feet = 0;
		inch = 0;
	}
	void inFoot(int x)
	{
		feet = x;
	}
	void inInch(int y)
	{
		if (y < 12)
			inch = y;
		else
		{
			inch = y % 12;
			feet += y / 12;
		}
	}
	void Meter_to_feet(double meter)
	{
		double a = 0.0;
		int b = 0;
		feet = meter / 0.3048;
		a = meter / 0.3048;
		b = meter / 0.3048;
		inch = (a - b) * 12;
	}
	void AddLength(int f, int i)
	{
		feet += f;
		if (inch + i < 12)
			inch += i;
		else
		{
			inch = (i + inch) - 12;
			feet++;
		}
	}
	void display()
	{
		cout << feet << " Feet " << inch << " Inch " << endl;
	}
	CLength operator + (int i)
	{
		CLength f;
		f.inFoot(feet);
		f.inInch(inch + i);
		return f;
	}
};
int main()
{
	CLength test;
	CLength a , c;
	double M;
	cin >> M;
	test.Meter_to_feet(M);
	test.display();
	test.AddLength(8, 4);
	test.display();
	//test.AddLength(9, 10);
	//test.display();
	c = test + 13;
	c.display();
	return 0;
}
