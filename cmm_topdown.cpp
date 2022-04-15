#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void matrix_chain_order(vector<int> p, vector<vector<int>> &m, vector<vector<int>> &s)
{
    //no of matrices
    int n = p.size()-1;
    for(int l = 2; l<n+1;l++)
    {
        //from where chain starts = i
        for(int i=1;i<=n-l+1;i++)
        {
            //till where chain goes = j
            int j = i+l-1;
            m[i-1][j-1] = INT_MAX;
            for(int k = i; k<j;k++)
            {
                int q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if (q<m[i-1][j-1])
                {
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}

void print_optimal_par(vector<vector<int>> &s, int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        print_optimal_par(s, i, s[i-1][j-1]);
        print_optimal_par(s, s[i-1][j-1]+1, j);
        cout<<")";
    }
}

int main()
{
    int n,i,j,ele;
    // n is the no of matrices +1
    cin >> n;
    vector<int> p(n);
    for(i = 0; i<n;i++)
    {
        cin >> p[i];
    }
    //declare our m table and s tables.
    vector<vector<int>> m(n-1, vector<int>((n-1),0));
    vector<vector<int>> s(n-1, vector<int>((n-1),0));
    matrix_chain_order(p,m,s);
    cout<<"mtable is"<<endl;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if (m[i][j] != 0);
                cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"stable is"<<endl;
    for(i=0;i<n-2;i++)
    {
        for(j=1;j<n-1;j++)
        {   
            if (s[i][j] != 0)
                cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"minimum cost is "<<m[0][n-2]<<endl;
    print_optimal_par(s,1,n-1);

}