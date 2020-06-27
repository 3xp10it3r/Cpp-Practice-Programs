#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int how_many;
	cout<<"Enter the size of the vector"<<endl;
	cin>>how_many;
	
	vector<int> data (how_many);
	
	for(vector<int>::iterator p=data.begin(); p!=data.end();++p)
	{
		cin>>*p;
	}
	
	for(vector<int>::iterator p=data.begin(); p!=data.end();++p)
	{
		cout<<*p<<endl;
	}
	return 0;
}
