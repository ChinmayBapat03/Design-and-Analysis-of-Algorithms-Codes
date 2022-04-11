
#include<iostream>
using namespace std;
#include<vector>
 

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (j = 1; j < n; j++)
    {
        key = a[j];
        i = j - 1;
 
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }

}
int linear_search(vector<int> elements, int key)
{
	int i,n;
	n = elements.size();
	for(i=0;i<n;i++)
	{
		if(key == elements[i])
			return i;
	}
	return -1;
}
int my_binary_search(vector<int> elements, int left,int right, int key)
{
	int mid;

	mid = (left+right)/2;
	if(key==elements[mid])
		return mid;
	if (key<elements[mid])
	{

		return my_binary_search(elements,left,mid-1,key);
	}
	else
		return my_binary_search(elements,mid+1,right,key);
}
void print(vector<int> v)
{
	int n,i;
	n = v.size();
	    for (i = 0; i < n; i++)
  	      cout << v[i] << " ";
}
int main()
{
   int n,i,k,x,pos;
   vector<int> elements;
   cout << "Enter n:";
   cin >> n;
   cout << "Enter numbers:";

      for (int i = 1; i <= n; i++)
      {
	  
        cin >> x;
        elements.push_back(x);
     }
   insertionSort(elements.data(),n);
   print(elements);
   cout << "Enter number to be searched:";
   cin >> k;
//   pos = linear_search(elements,k);
	pos = my_binary_search(elements,0,n-1,k);
	cout<<"Position of element is "<<pos+1;
    return 0;
}

