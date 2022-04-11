// Non negative contigious


//Iterative -- By calculating change


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
    	if(i<0)
    	{
    		continue;
		}
    	curr_sum=0;    
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
	cout<<ans.sum;
}
