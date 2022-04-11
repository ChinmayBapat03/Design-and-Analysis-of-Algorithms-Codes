// minimum val min subarray

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

struct details
{
	int low;
	int high;
	int sum;
	int length;
};

details find_min_subarray(vector<int> a, int n)
{
	details d;
	int min_sum = 0;
	for (int i = 0; i<n; i++)
	{
		int curr_sum = 0;
		for (int j = i; j<n; j++)
		{
			curr_sum = curr_sum + a[j];
			if(curr_sum == d.sum)
			{
				int l = j-i;
				if (l < d.length)
				{
					d.sum = curr_sum;
					d.low = i;
					d.high = j;
					d.length = j - i;
				}
			}
			if(curr_sum < d.sum)
			{
				d.sum = curr_sum;
				d.low = i;
				d.high = j;
				d.length = j - i;
			}
		}
		
	}
	return d;
}

int main()
{
	vector <int> a;
	int n, ele;
	cin >> n;
	for (int k = 0; k<n; k++)
	{
		cin>> ele;
		a.push_back(ele);
	}
	details ans;
	ans = find_min_subarray(a, n);
	cout<<ans.low<<endl;
	cout<<ans.high<<endl;
	cout<<ans.sum<<endl;
	//cout<<ans.length;
}
