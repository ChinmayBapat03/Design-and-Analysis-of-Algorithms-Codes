#include <iostream>
#include <math.h>
using namespace std;

int p(int n)
{
    long int k, sum = 0;
    if(n==1)
        return 1;
    for(k=1; k<n; k++)
    {
        sum += p(k)*p(n-k);
    }
    return sum;
}

int main()
{
    long double n;
    long double nr, dr;
    cin >> n;
    cout << p(n);
    return 0;
}