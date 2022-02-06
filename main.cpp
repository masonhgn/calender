/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Date class
/////////////////////////////////////////////////////////

#include <iostream>
#include "date.cpp"

using namespace std;

int main()
{
    Date d1(3,30,1999);		// should default to 1/1/2000
    Date d2(11,21,1958);  // should init to 4/10/1992
    Date d3(1,1,2006);

    d1.Increment(5000);
    d2.Increment(201);
    d3.Increment(36243);

    d1.Show();
    d2.Show();
    d3.Show();

}



