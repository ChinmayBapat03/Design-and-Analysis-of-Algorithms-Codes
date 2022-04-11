#include<iostream>
#include<vector>
#include<ctime> 
#include<limits.h>
#include <cmath>
using namespace std;

void merge(vector<int> &elements, int left, int mid, int right)
{
	vector<int> left_Sub_Array, right_Sub_Array;
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
void mergesort(vector<int> &elements, int left, int right)
{
	int mid;
	// When there is only one element in the array
	if(left==right)
		return;
	// Find mid of the array
	mid = (left+right)/2;
	// call mergesort for left subarray
	mergesort(elements,left,mid);
	// call mergesort for right subarray
	mergesort(elements,mid+1,right);
	// merge the sorted left and right subarray
	merge(elements,left,mid,right);


}

class Point
{
	public:
		int x1;
		int y1;
		int x2 = 0;
		int y2 = 0;
		int d;
		bool flag;
	
	int dist()
	{
		int dist_org = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
		return dist_org;
	}
};

void print(vector<int> v)
{
	int n,i;
	n = v.size();
	    for (i = 0; i < n; i++)
  	      cout << v[i] << " ";
}

int main()
{
	int n;
	cout <<"Enter n:" <<endl;
	cin >> n;
	vector <int> ycoords;
	vector<Point> Point_list;
	for (int i = 0; i<n; i++)
	{
		Point p;
		cin >> p.x1 >> p.y1;
		ycoords.push_back(p.y1);
		Point_list.push_back(p);
		
	}
	mergesort(ycoords, 0, n-1);
	//print(ycoords);
	int l = ycoords.size();
	for (int i = 0; i<l; i++)
	{
		for (int j = 0; j<l; j++)
		{
			if (ycoords[i] == Point_list[j].y1 && Point_list[j].flag != 1)
			{
				Point_list[j].flag = 1;
				cout << Point_list[j].x1 << endl;
				cout << Point_list[j].y1 << endl;
			}
		}
	}
	return 0;
}

