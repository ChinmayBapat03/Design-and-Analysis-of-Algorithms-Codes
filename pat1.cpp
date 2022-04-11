//Recursive Code

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
//creating struct
struct details
{
	int low;
	int high;
	int value;
	int length;
};

vector<details> same; //global declaration of vector of details to store subarray info of values same to max value.

details find_max_subarray(vector<int> a, int i)
{
	int j, curr_value = 0;
	static details d = {0, a.size()-1, INT_MIN, a.size()-1};
	if (i==a.size()){
		return d;
	}
	//calculating value
	for (j = i; j<a.size(); j++)
	{
		int curr_sum = curr_sum + a[j];
		int den = j-i+1;
		curr_value = curr_sum/den;
		if (curr_value > d.value)
		{
			d.value = curr_value;
			d.low = i;
			d.high = j;
			d.length = j-i;
		}
		//if equal, we need to compare lengths
		if(curr_value = d.value)
		{
			details temp;
			temp.low = i;
			temp.high = j;
			temp.value = curr_value;
			temp.length = j-i;
			
			same.push_back(temp);
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
	vector<int> l;
	if(same.size() != 0)
	{
		for (int i = 0; i<same.size(); i++)
		{
			l.push_back(same[i].length);
		}
		
		int min = *min_element(l.begin(), l.end());
		
		if (min < ans.length)
		{
			for(int i = 0; i<same.size(); i++)
			{
				if (min = same[i].length)
				{
					ans.low = same[i].low;
					ans.high = same[i].high;
					ans.value = same[i].value;
					ans.length = same[i].length;
				}
			}
		}
	}
	cout << ans.value<< endl;
	for (int i = ans.low; i<ans.high; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
