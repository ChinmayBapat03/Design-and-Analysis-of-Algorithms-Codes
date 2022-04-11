
//Bottom up approach cut rod at even lengths only

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>

int maximum(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int bottom_up_cut_rod(vector<int> &p, int length)
{
vector<int> r(100,0);
int i,q,j;
r[0] = 0;
for (j=1;j<=length;j++)
{
	{
		q = INT_MIN;
		int val;
		for(i=1;i<=j;i++)
		{
			if ((j-i)%2 == 0)
			{
				val = p[i-1]+r[j-i];
			}
			else
			{
				q = p[j-1];
			}
			q = maximum(val, q);
		}
		r[j] = q;
		cout<<"Max for "<<j<<" "<<q<<endl;
	}
	
}
	return r[length];
}

int main()
{
vector<int> p;
int i,n,price,max_rev;
cin>>n;
for(i=0;i<n;i++)
{
	cin>>price;
	p.push_back(price);
}
max_rev = bottom_up_cut_rod(p,n);
cout<<max_rev;
}
