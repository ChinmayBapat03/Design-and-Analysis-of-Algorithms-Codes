
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;
 
void insertionSort(char a[], int n)
{
    int i, j;
    char key;
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
void print(char v[],int n)
{
	int i;
	for (i = 0; i < n; i++)
        cout << v[i] << " ";
}
 
int main()
{
   char a[26];
   int n,i;
   //int cnt= 0;
   //int x;
   cin>>n;
  for(i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   //clock_t tStart = clock();   
   insertionSort(a, n);
   //double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;

    print(a,n);
	//cout<<"Time taken is "<<time1<<endl;
    return 0;
}

