// Insertion with merge sort


#include<iostream>
using namespace std;
#include<vector>
#include<ctime> 
#include<limits.h>

int counter = 0;

void insertionSort(float a[], int start, int end)
{
    int i, j;
    float key;
    for (j = start+1; j < end; j++)
    {
        key = a[j];
        i = j - 1;
 
        while (i >= start && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }

}

void merge(vector<float> &elements, int left, int mid, int right)
{
	vector<float> left_Sub_Array, right_Sub_Array;
	int no_Left_Sub,no_Right_Sub,i,index_Left_SA,index_Right_SA,index_Full_Array;
	// Find number of elements in left subarray
	no_Left_Sub = mid-left+1;
	// Find number of elements in right subarray
	no_Right_Sub = right-mid;
	//make a copy of left sub array in a temporary array
	for(i=0;i<no_Left_Sub;i++)
		left_Sub_Array.push_back(elements[left+i]);
	//make a copy of right sub array into another temporary array
	for(i=0;i<no_Right_Sub;i++)
		right_Sub_Array.push_back(elements[mid+i+1]);
	// Position the indices for the three arrays rightly
	index_Left_SA=0;
	index_Right_SA=0;
    
	
	left_Sub_Array[no_Left_Sub] = INT_MAX;
	right_Sub_Array[no_Right_Sub] = INT_MAX;
	for(index_Full_Array=left;index_Full_Array<=right;index_Full_Array++)
	{
		if(left_Sub_Array[index_Left_SA]<=right_Sub_Array[index_Right_SA])
		{
			elements[index_Full_Array] = left_Sub_Array[index_Left_SA];
			index_Left_SA++;
		}
		else
		{
			elements[index_Full_Array] = right_Sub_Array[index_Right_SA];
			index_Right_SA++;
		}
	}
}

void mergesort(vector<float> &elements, int left, int right)
{
	int mid;
	// When there is only one element in the array
	if(left==right)
		return;
	// Find mid of the array
	mid = (left+right)/2;
	counter++;
	if(counter == 1)
	{
		insertionSort(elements.data(),mid+1,right);
	}
	// call mergesort for left subarray
	mergesort(elements,left,mid);
	merge(elements,left,mid,right);
}

int main()
{
	int n,i;
	float ele;
	vector<float> elements;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}

	mergesort(elements, 0, n-1);
	for(i=0;i<n;i++)
	{
		cout<<elements[i]<<endl;
	}
}
