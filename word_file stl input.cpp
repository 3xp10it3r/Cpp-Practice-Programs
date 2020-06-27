#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	 ifstream word_file("word_filex.txt");
	 istream_iterator<string> start(word_file),end;
	 vector<string> word(start,end);
	 
	 cout<<"Before sorting : "<<endl;
	 for(vector<string>::iterator it= word.begin(); it!=word.end();++it){
	 	cout<<*it<<endl;
	 }
	 cout<<endl;
	 sort(word.begin(), word.end());
	 cout<<"After Sorting :"<<endl;
	 for(vector<string>::iterator it = word.begin(); it!=word.end(); ++it){
	 	cout<<*it<<endl;
	 }
}
