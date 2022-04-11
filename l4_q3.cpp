//Kadane's Algo


#include<iostream>
#include<climits>
#include <vector>
using namespace std;
 
int high_counter=0;
int low_counter=0;
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here){
             max_so_far = max_ending_here;
             high_counter++;
        }
            
 
        if (max_ending_here < 0){
            max_ending_here = 0;
            low_counter++;
        }
    }
    return max_so_far;
}
 
int main()
{
    vector<int> v;
    int n, ele;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
    	cin >> ele;
    	v.push_back(ele);
	}
    int max_sum = maxSubArraySum(v.data(), n);
    cout<<low_counter+1<<endl;
    cout<< high_counter<<endl;
    cout<< max_sum<<endl;
    return 0;
}
