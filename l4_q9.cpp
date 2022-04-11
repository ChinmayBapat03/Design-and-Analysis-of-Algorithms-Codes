//Max value min subarray

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
struct details
{
    int low;
    int high;
    int sum;
    int length;
};
details find_maximum_subarray(vector<int> a)
{
    int i, j, n, max_left,max_right, max_sum,curr_sum, max_length;
    details d;
    max_sum = INT_MIN;
    n = a.size();
    
    for(i=0;i<n;i++)
    {
    	curr_sum=0;
        for(j=i;j<n;j++)
        {
            curr_sum += a[j];
            if(curr_sum == max_sum)
            {
            	int l = j-i;
            	if(l < max_length)
            	{
            		max_sum = curr_sum;
                	max_left = i;
                	max_right = j;
                	max_length = j-i;
				}
			}
            if(curr_sum>max_sum)
            {
                max_sum = curr_sum;
                max_left = i;
                max_right = j;
                max_length = j-i;
            }
        }
    }
    d.low = max_left+1;
    d.high = max_right+1;
    d.sum = max_sum;
    d.length = max_length;
    return d;
}
int main()
{
    vector<int> elements;
    int low,high,n,i,ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    
    ans = find_maximum_subarray(elements);
    cout<<ans.low<<endl;
	cout<<ans.high<<endl;
	cout<<ans.sum<<endl;
}
