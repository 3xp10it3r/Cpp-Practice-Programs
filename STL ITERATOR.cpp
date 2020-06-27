#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	ifstream data_file("sum.txt");
	istream_iterator<int> start(data_file),end;
	vector<int> data(start,end);
	
	int sum = 0;
	
	for(vector<int>::iterator it=data.begin();it!=data.end();++it){
		sum += *it;
	}
	cout<<sum<<endl;
	cout<<"Average is "<<1.0*sum/data.size();
}
