#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

/*
aabcacd
abc
*/

int pattern_checker(string t, string p, int index, int diff)
{
    //matching case.
    bool match = false;
    for(int i = 0; i<p.length(); i++)
    {
        if(t[index+i] == p[i])
        {
            match = true;
        }
        else
        {
            match = false;
            break;
        }
    }
    if (match == true)
    {
        cout<<"Matching"<<endl;
        return 1;
    }
    //first dec case
    bool dec = false;
    for(int i = 1; i<diff; i++)
    {
        if(((t[index+i] - p[i]) < (t[index+i-1]-p[i-1])))
        {
            dec = true;
        }
        else
        {
            dec = false;
            break;
        }
    }
    if(dec == true && (t[index] == p[0]))
        {
            cout << "First match decreasing"<<endl;
            return 2;
        }
    //first inc case
    bool inc = false;
    for(int i = 1; i<diff; i++)
    {
        if(((t[index+i] - p[i]) > (t[index+i-1]-p[i-1])))
        {
            inc = true;
        }
        else
        {
            inc = false;
            break;
        }
    }
    if(inc == true && (t[index] == p[0]))
        {
            cout << "First match increasing"<<endl;
            return 3;
        }
    //no match case
    bool nomatch = false;
    for(int i = 0; i<p.length(); i++)
    {
        if(t[index+i] != p[i])
        {
            nomatch = true;
        }
        else
            nomatch = false;
            break;
    }
    if (nomatch == true)
    {
        cout<<"Not matching"<<endl;
        return 4;
    }
}

int main()
{
    string t, p;
    cin >> t;
    cin >> p;
    //cout << t << " "<<p;
    int diff = t.length()-p.length();
    for(int j = 0; j<=diff; j++)
    {
        int ans = pattern_checker(t, p, j, diff);
    }
    return 0;
}