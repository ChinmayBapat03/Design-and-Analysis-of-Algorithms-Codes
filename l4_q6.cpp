//Recursive Code

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct details
{
	int low;
	int high;
	int sum;
};

details find_max_subarray(vector<int> a, int i)
{
	int j, curr_sum = 0;
	static details d = {0, a.size()-1, INT_MIN};
	if (i==a.size()){
		return d;
	}
	for (j = i; j<a.size(); j++)
	{
		curr_sum += a[j];
		if (curr_sum > d.sum)
		{
			d.sum = curr_sum;
			d.low = i+1;
			d.high = j+1;
		}
	}
	return find_max_subarray(a, i+1);
}


int main()
{
	vector<int> a;
	int low, high, i, ele, n;
	details ans;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cin>>ele;
		a.push_back(ele);
	}
	
	ans = find_max_subarray(a, 0);
	cout << ans.low<<endl;
	cout << ans.high<<endl;
	cout << ans.sum<<endl;
}
