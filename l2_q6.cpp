#include <iostream>
#include <time.h>
#include <cmath>
#include <vector>
using namespace std;


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

int main()
{
	int n;
	cout <<"Enter n:" <<endl;
	cin >> n;
	vector <int> xcoords;
	vector<Point> Point_list;
	for (int i = 0; i<n; i++)
	{
		Point p;
		cin >> p.x1 >> p.y1;
		//p.d = p.dist();
		xcoords.push_back(p.x1);
		Point_list.push_back(p);
		
	}
	insertionSort(xcoords.data(), xcoords.size());
	//print(xcoords);
	//cout << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (xcoords[i] == Point_list[j].x1 && Point_list[j].flag != 1)
			{
				Point_list[j].flag = 1;
				cout << Point_list[j].x1 << endl;
				cout << Point_list[j].y1 << endl;
			}
		}
		//cout << Point_list[i].d << " ";
	}
	return 0;
}
