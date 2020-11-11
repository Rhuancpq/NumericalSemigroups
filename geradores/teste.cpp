#include <iostream>
using namespace std;

int main(){
    int a, b, c = 0;
    cin >> a >> b;
    c += (-36 + (-18)*a + 5*b)*2;
    c += (18 + 9*a -2*b)*5;
    c += (-1*a)*9;
    cout << c << endl;
    return 0;
}