#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int lcs_length(string x, string y, int x_index, int y_index, vector<vector<int> > &c)
{
    int m,n,l1,l2,val,i,j;
    m = x.length();
    n = y.length();
    //when the index exceeded
    if((x_index<=0 )|| (y_index <=0))
    {
        return 0;
    }
    //when the strings are same
    if ((x[x_index-1]) == (y[y_index-1]))
    {
        //check if there is an entry in the table
        if(c[x_index][y_index] != -1)
        {
            return c[x_index][y_index];
        }
        //if no entry then find the diagonal entry and add one
        val = lcs_length(x,y, x_index-1, y_index-1, c)+1;
        //store it in table
        c[x_index][y_index] = val;
        return val;
    }
    else
    {
        //check if 'up' entry is present, if yes store in l1
        if(c[x_index][y_index-1] != -1)
        {
            l1 = c[x_index][y_index-1];
        }
        else{
            //otherwise compute l1 by moving in second string
            l1 = lcs_length(x,y,x_index, y_index-1, c);
            //store in table
            c[x_index][y_index-1] = l1;
        }
        //check if left entry is computed
        if (c[x_index-1][y_index] != -1)
        {
            l2 = c[x_index-1][y_index];
        }
        else{
            l2 = lcs_length(x,y,x_index-1, y_index, c);
            c[x_index-1][y_index] = l2;
        }
        
        return l1>l2 ? l1:l2;
    }
    cout<<endl;
}

int main()
{
    string x,y;
    int i, j;
    cin >> x >> y;
    int m = x.length();
    int n = y.length();
    vector<vector<int>> c(m+1, vector<int>(n+1, -1));
    vector<char> seq;
    for(i=0; i<m+1; i++)
    {
        c[i][0] = 0;
    }
    for(j=0; j<n+1;j++)
    {
        c[0][j] = 0;
    }
    cout<<lcs_length(x,y,m,n,c)<<endl;
    for(int u = 0; u<m+1; u++)
    {
        for (int v = 0; v<n+1; v++)
        {
            cout<<c[u][v]<<" ";
            if(c[u][v]>0)
                seq.push_back(x[v]);
        }
        cout<<endl;
    }
    for (int o = 0; o<seq.size()+1; o++)
        cout<<seq[o]<<" ";
    return 0;
}