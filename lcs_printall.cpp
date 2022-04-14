//LCS BOTTOM UP DYNAMIC PROGRAMMING USING B TABLE AND C TABLE

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void lcs_length_bu(string x, string y, vector<vector<int> >&c, vector<vector<char> > &b)
{
	int m = x.length()+1;
	int n = y.length()+1;
	
	for (int i = 1; i<m; i++)
	{
		for (int j = 1; j<n; j++)
		{
			if(x[i-1] == y[j-1])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'd';
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 'l';
			}
		}
	}
}

void print_LCS(vector<vector<char> >&b, string x, int i, int j)
{
	if((i==0)|| (j==0))
	{
		return;
	}
	if(b[i][j] == 'd')
	{
		print_LCS(b, x, i-1, j-1);
		cout << x[i-1];
	}
	else if(b[i][j] == 'u')
	{
		print_LCS(b, x, i-1, j);
	}
	else if(b[i][j] == 'l')
	{
		print_LCS(b, x, i, j-1);
	}
}

int main()
{
	string x, y;
	int i,j;
	cin >> x >>y;
	vector<vector<int> > c(x.length()+1, vector<int>(y.length()+1, 0));
	vector<vector<char> > b(x.length()+1, vector<char>(y.length()+1, ' '));
	lcs_length_bu(x,y,c,b);
	for(i = 0; i<x.length()+1; i++)
	{
		for (j = 0; j<y.length()+1; j++)
			cout<<c[i][j]<<" ";
		cout << endl;
	}
	for (i = 0; i<x.length()+1; i++)
	{
		for(j = 0; j<y.length()+1; j++)
		{
			cout << b[i][j]<<" ";
		}
		cout << endl;
	}

	for(j = 0; j<y.length()+1; j++)
	{
        print_LCS(b,x,x.length(), j);
        cout<<endl;
	}
	//cout << endl;

	//print_LCS(b,x,x.length(), y.length());
}
