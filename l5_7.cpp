#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maximum(int a, int b)
{
	if (a>b)
		return a;
	return b;
}

void rodsize(vector <pair <int, int> > &v ,int length, int n)
{
	if(v[length-1].second==0)
	{
		cout << v[length-1].first << " ";
		return ;
	}
	cout << v[length-1].first<<" ";
	rodsize(v, v[length-1].second, n);
}

int bu_cut(vector <int> &p, int length, int n)
{
	int q, i, j;
	vector <int> r(100, 0);
	pair <int, int> one_split(0,0);
	vector<pair<int, int> >splits(100, one_split);
	r[0] = 0;
	for(j = 1; j<=length; j++)
	{
		q = INT_MIN;
		for(int i = 1; i<=j; i++)
		{
			if((q==INT_MIN)||(p[i-1]+r[j-i]>q))
			{
				splits[j-1].first = i;
				splits[j-1].second = j-i;
				q = p[i-1] + r[j-i];
			}
		}
		r[j] = q;
	}
//	for(i = 0; i<length; i++)
//	{
//		cout <<splits[i].first << " "<<splits[i].second<<endl;
//	}
	
	rodsize(splits, length, n);
	return r[length];
}

int main()
{
	vector <int> p;
	int i, n, price, max_rev;
	cin>>n;
	for(i = 0; i<n; i++)
	{
		cin>>price;
		p.push_back(price);
	}
	max_rev = bu_cut(p, n, n);
	cout<<max_rev;
	
	return 0;
}
