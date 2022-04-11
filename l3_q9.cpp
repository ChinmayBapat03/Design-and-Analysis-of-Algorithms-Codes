#include<iostream>
#include<vector>
using namespace std;

// last element is taken as pivot
int Partition(vector<float> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<float> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

void PrintVector(vector<float> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<< endl;
}

int main() {
	
	int n;
	//cout << "Enter n: ";
	cin >> n;
	vector<float> v;
	for (int i = 0; i<n; i++)
	{
		float val;
		cin >> val;
		v.push_back(val);
	}
	
	Quicksort(v,0,v.size()-1);
	
	PrintVector(v);
		
}
