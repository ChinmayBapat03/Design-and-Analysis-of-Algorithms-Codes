
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
    int i, j, n, max_left,max_right, max_profit,profit;
    details d;
    max_profit = INT_MIN;
    n = a.size();
    profit=0;
    for(i=1;i<n;i++)
    {
        profit = 0;
        // size of subarray will be from 1 to n - i and ith element is part of it
        for(j=i;j<n;j++)
        {
            profit = profit + (a[j]-a[i]);
            if(profit>max_profit)
            {
                max_profit = profit;
                max_left = i;
                max_right = j;
            }
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = max_profit;
    return d;


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

  ans = find_maximum_subarray(elements);
    cout<<ans.low<<" "<<ans.high<<" "<<ans.sum<<endl;

    ----------------------
#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>
// 13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
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
    int low,high,n,i,ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        elements.push_back(ele);
    }
    
    ans = find_maximum_subarray(elements);
    cout<<ans.low<<" "<<ans.high<<" "<<ans.sum<<endl;
}













using namespace std;
#include<vector>
#include<limits.h>
struct details
{
    int low;
    int high;
    int sum;
};
details find_max_crossing_subarray(vector<int> a, int low, int mid, int high)
{
    int left_sum, right_sum, sum, i, max_left, max_right;
    details d;
    sum = 0;
    left_sum = INT_MIN;
    for(i=mid;i>=low;i--)
    {
        sum += a[i];
        if (sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    right_sum = INT_MIN;
    sum=0;
    for(i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if (sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    d.low = max_left;
    d.high = max_right;
    d.sum = left_sum + right_sum;
    return d;
}
details find_maximum_subarray(vector<int> a,int low,int high)
{
    details left_details,right_details,cross_details,d;
    int mid;
    if(low==high)
    {
        d.low = low;
        d.high = high;
        d.sum = a[low];
        return d;
    }
    mid = (low+high)/2;
    left_details = find_maximum_subarray(a,low,mid);
    right_details = find_maximum_subarray(a,mid+1,high);
    cross_details = find_max_crossing_subarray(a,low,mid,high);
    if((left_details.sum>=right_details.sum)&&(left_details.sum>=cross_details.sum))
        return left_details;
    else if((right_details.sum>=left_details.sum)&&(right_details.sum>=cross_details.sum))
        return right_details;
    else
        return cross_details;
}
int main()
{
    vector<int> A;
    int low,high,n,i,ele;
    details ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        A.push_back(ele);
    }
    ans = find_maximum_subarray(A,0,n-1);
    cout<<ans.low<<" "<<ans.high<<" "<<ans.sum<<endl;
}






















