//LCS BOTTOM UP DYNAMIC PROGRAMMING USING B TABLE AND C TABLE

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<char> seq;
vector<vector<int>> sw;
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
		//cout << x[i-1];
        seq.push_back(x[i-1]);
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
	// for(i = 0; i<x.length()+1; i++)
	// {
	// 	for (j = 0; j<y.length()+1; j++)
	// 		cout<<c[i][j]<<" ";
	// 	cout << endl;
	// }
	// for (i = 0; i<x.length()+1; i++)
	// {
	// 	for(j = 0; j<y.length()+1; j++)
	// 	{
	// 		cout << b[i][j]<<" ";
	// 	}
	// 	cout << endl;
	// }
	print_LCS(b,x,x.length(), y.length());
    for(int g = 0; g<seq.size(); g++)
    {
        vector<int> temp;
        int ind1,ind2;
        for (int s = 0; s<x.length(); s++)
        {
            if (seq[g] == x[s])
                ind1 = s+1;
        }
        for (int s = 0; s<y.length(); s++)
        {
            if (seq[g] == y[s])
                ind2 = s+1;
        }
        if(ind1>ind2){
            temp.push_back(ind2);
            temp.push_back(ind1);
        }

        else{
            temp.push_back(ind1);
            temp.push_back(ind2);
        }
        sw.push_back(temp);
    }
    for (int h = 0; h<sw.size(); h++){
		for(int k = 0; k<2; k++){
			cout << sw[h][k]<<" ";
		}
		cout<<endl;
    }
}
