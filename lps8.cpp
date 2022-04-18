#include<iostream>
using namespace std;
#include<string>
#include<math.h>
int valueOf(char ch)
{
    // if(int(ch) >= 97 && int(ch) <= 122)
    //     return (int(ch)-61);
    // else if(int(ch) >= 65 && int(ch) <= 90)
    //     return (int(ch) - 55);
    return (ch-'0');
}
bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}
void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i,s;
    int counter = 0;
    n = T.length();
    m = P.length();
    h = (int)pow(d,m-1)%q;
    //cout<<"h value is "<<h<<endl;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q;
        t0 = (d*t0 + valueOf(T[i]))%q;
    }
    for(s=-1;s<n-m;s++)
    {
        //cout<<p<<" "<<t0<<endl;
        if(p==t0)
        {
            counter++;
            if (check_characters(T,P,s))
                cout<<s+1<<endl;
        }
        if(s<n-m)
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q;
    }
    cout<<counter<<endl;
}
int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}

