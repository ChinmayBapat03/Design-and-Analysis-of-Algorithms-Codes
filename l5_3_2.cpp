#include <iostream>
#include <vector>
using namespace std;
#include <limits.h>
vector <int> rev_list(100, -1);


int maximum_no(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int mem_rod_aux(vector <int> price, int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (rev_list[n-1] >= 0)
	{
		return rev_list[n-1];
	}
	int q = INT_MIN;
	int val;
	for (int i = 1; i<n; i++)
	{
		val = maximum_no(q, price[i-1] + mem_rod_aux(price, n-i));
	}
	rev_list[n-1] = val;
	return val;
}

int mem_rod(vector<int> price, int n)
{
//	for(int i = 0; i<n; i++)
//	{
//		rev_list[i] = -1;
//	}
	return mem_rod_aux(price, n);
}

int main()
{
	int n;
	cout <<"Enter n: "<<endl;
	cin >> n;
	vector <int> price;
	for (int i = 0; i<n; i++)
	{
		int val;
		cin >> val;
		price.push_back(val);
	}
	int max_rev = mem_rod(price, n);
	for (int j = 0; j<price.size(); j++)
	{
		cout << price[j] << "	";
	}
	cout << "Max revenue is: "<<endl;
	cout << max_rev;
	
	return 0;
}
