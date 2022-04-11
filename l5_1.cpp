#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>
using namespace std;

#define size 75

long long result[size];

long long Fibonacci(int n)
{
	if (n==1){
			result[n] = 0;
		}
		if (n==2){
			result[n] = 1;
		}
		if (n==3){
			result[n] = 2;
		}
	if (result[n] == -1)
	{
		{
			result[n] = Fibonacci(n-1) + Fibonacci(n-2) + Fibonacci(n-3);
		}
	}
	return result[n];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<size; i++)
	{
		result[i] = -1; //indicates that this is not computed yet.
	}
	long long val = Fibonacci(n);
	cout << val <<endl;
	
	return 0;
}


