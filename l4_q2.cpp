//Character

#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
struct details
{
    int low;
    int high;
    int sum;
};
details find_maximum_subarray(vector<int> a)
{
    int i, j, n, max_left,max_right, max_sum,curr_sum;
    details d;
    max_sum = INT_MIN;
    n = a.size();
    
    for(i=0;i<n;i++)
    {
    	curr_sum=0;    
        // size of subarray will be from 1 to n - i and ith element is part of it
        for(j=i;j<n;j++)
        {
            curr_sum += a[j];
            if(curr_sum>max_sum)
            {
                max_sum = curr_sum;
                max_left = i;
                max_right = j;
            }
        }
    }
    d.low = max_left+1;
    d.high = max_right+1;
    d.sum = max_sum;
    return d;
}
int main()
{
    vector<int> elements;
    int low,high,n,i;
    char ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        int val = int(ele);
        if (val < 97){
        	int new_val = -val;
        	elements.push_back(new_val);
		}
		else{
			elements.push_back(val);
		}
    }
    
    ans = find_maximum_subarray(elements);
    cout<<ans.low<<endl;
    cout<<ans.high<<endl;
    cout<<ans.sum<<endl;
}
