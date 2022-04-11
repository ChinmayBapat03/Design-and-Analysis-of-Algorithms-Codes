#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

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

void print(int v[], int n)
{
	int i;
	    for (i = 0; i < n; i++)
  	      cout << v[i] << endl;
}

void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int numbers[10], n;
	cout << "Enter n:"<<endl;
	cin >> n;
	cout << "Enter numbers: "<<endl;
	for (int i = 0; i<n; i++)
	{
		cin >> numbers[i];
	}
	insertionSort(numbers, n);
	//print(numbers, n);
	int pos;
	bool flag = 0;
	for (int i = 0; i<n; i++)
	{
		if (numbers[i]==0)
		{
			pos = i-1;
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		for (int i = pos; i>=0; i--)
		{
			cout << numbers[i] << " "; //printing 
		}
		for (int i = pos+1; i<n; i++)
		{
			cout << numbers[i] << " ";
		}
	}
	else
	{
		print(numbers, n);
	}
	
	return 0;
}
