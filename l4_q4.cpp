//Inversion Problem


#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int counter = 0;

void icount(vector <int> v, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-(q+1);
	int L[n1+1], R[n2+1];
	for(int i = 1; i<n1; i++)
	{
		L[i] = v[p+i-1];
	}
	for(int j = 1; j<n2; j++)
	{
		R[j] = v[q+j];
	}
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	
	int x = 1;
	int y = 1;
	
	for (int k = p; k<r; k++)
	{
		if(L[x] <= R[y])
		{
			v[k] = L[x];
			x++;
		}
		else
		{
			v[k] = R[y];
			y++;
		}
		
	}
	for (int m = n2; m>q; m--)
	{
		if(L[n1] > R[m])
		{
			counter = counter + (n1*(m-q));
		}
	}
};

void inversion(vector <int> v, int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;//mid
		inversion(v, p, q);
		inversion(v, q+1, r);
		icount(v, p, q, r);
	}
};


int main()
{
	vector <int> v;
	int n, ele;
	for (int i = 0; i<n; i++)
	{
		cin >> ele;
		v.push_back(ele);
	}
	inversion(v, 0, n);
	cout << counter;
	return 0;
}
