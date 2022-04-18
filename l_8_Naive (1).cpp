/// for non overlapping indices...
#include<iostream>
using namespace std;
#include<string>
#include <vector>

bool check_pattern(string T, string P, int s)
{
    int m = P.length(),i;
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;

}
void naive_string_matcher(string T, string P)
{
    int n,m,s,i;
    n = T.length();
    m = P.length();
    vector<int> over(n,0);

    for(s=-1;s<=n-m-1;s++)
    {
        if (check_pattern(T,P,s))
        {
        	if((over[s+1] == 0 && over[s+2] == 0))
        	{
        		over[s+1] = 1;
				over[s+2] = 1;
    			cout<<<<s+1<<endl;
			}
		}    
	}

}
int main()
{

    string T, P;
    cin>>T>>P;
    naive_string_matcher(T,P);


}
