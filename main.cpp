#include <iostream>
#include "date.cpp"

using namespace std;
int main() {
    Date d1(2,4,2001);
    d1.SetFormat('t');
    d1.Increment(801);
    d1.Show();
    d1.Increment(32);
    d1.Show();
    d1.Increment(6739);
    d1.Show();
    d1.Increment(67349);
    d1.Show();


    return 0;
}



