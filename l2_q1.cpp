#include <iostream>
#include <fstream>


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
void print(int v[],int n)
{
	int i;
	for (i = 0; i < n; i++)
        cout << v[i] << " ";
}
 
int main()
{
   int a[100000],n,i;
   //ifstream is("descending.txt");
   int cnt= 0;
   int x;
  // cin>>n;
/*   for(i=0;i<n;i++)
   cin>>a[i];*/
   //while ( is >> x)
   
       //a[cnt++] = x;

   //clock_t tStart = clock();   
   insertionSort(a, cnt-1);
    //double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;

//    print(a,cnt);
	//cout<<"Time taken is "<<time1<<endl;
    return 0;
}

