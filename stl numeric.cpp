#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream myin("sum.txt");
	istream_iterator<int> in(myin);
	istream_iterator<int> eos;
	
	cout<<accumulate(in,eos,0);
	
}
