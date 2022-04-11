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

void print(vector<int> v)
{
	int n,i;
	n = v.size();
	    for (i = 0; i < n; i++)
  	      cout << v[i] << " ";
}
void printc(vector<char> v)
{
	int n,i;
	n = v.size();
	    for (i = 0; i < n; i++)
  	      cout << v[i] << " ";
}

int main()
{
	vector <char> alpha;
	vector <int> numbers;
	vector <char> alpha_new;
	int n;
	cout << "Enter n: "<< endl;
	cin >> n;
	cout << "Enter alphabets: "<< endl;
	char x;
	for (int i = 0; i<n; i++)
	{
		cin >> x;
		alpha.push_back(x);
		int value = int(x) - 96;
		numbers.push_back(value);
	}
	insertionSort(numbers.data(), numbers.size());
	for (int j = 0; j<numbers.size(); j++)
	{
		int value = (numbers[j]+96);
		alpha_new.push_back(char(value));
	}
	printc(alpha_new);
	return 0;
}
