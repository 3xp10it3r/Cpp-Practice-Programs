#include <iostream>

using namespace std;

#define foo1( a ) (a * a)

inline int foo2( int a ) { return (a * a); }

inline int goo1( int x ) { return foo1(foo2(x)); }

inline int goo2( int& x ) { return x = foo2(foo1(x)); }

inline int goo3( int& x, int y ) { return foo2(foo1(y + 1)); }

inline void goo4( int& x, int y ) { x = foo1(foo2(y + 1)); }

int main()

{

int a = 2, b = -3, c = 2;

bool tval1 = false, tval2 = true;

char ch = 'b';

cout<<b+c*a<<endl;
cout<<c%5/2<<endl;
cout<<-a*c++<<endl;
cout<<tval1 && tval2;
ch += 2;
cout<<ch<<endl;
return 0;

}
