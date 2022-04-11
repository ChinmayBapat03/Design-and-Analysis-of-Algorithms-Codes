#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>

int maximum(int a, int b)
{
	if (a>b)
		return a;
	return b;
}

int cut(int n, int p3, int p5)
{
	int cut_3 , cut_5 = -1;
	if(n < 3)
	{
		return n*-1;
	}
	if(n>=3 && n<5)
	{
		cut_3 = p3 + cut(n-3, p3, p5);
	}
	else
	{
		cut_3 = p3 + cut(n-3, p3, p5);
		cut_5 = p5 + cut(n-5, p3, p5);
	}
	int q = maximum(cut_3, cut_5);
	return q;
}

int main()
{
	int max_rev, p3, p5, n;
	cin >> n;
	cin >> p3 >> p5;
	max_rev = cut(n, p3, p5);
	cout << max_rev;
	return 0;
}
