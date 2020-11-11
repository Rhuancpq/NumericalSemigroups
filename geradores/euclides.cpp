#include <math.h>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef struct eq{
    int a, b;
}eq;


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

vector<int> solution_n(vector<int> v, int c){
    if(v.size() == 2){
        int x0, y0, g;
        vector<int> sol;
        find_any_solution(v.front(), v.back(), c, x0, y0, g);
        sol.push_back(x0);
        sol.push_back(y0);
        return sol;
    }
    int x0, y0, g;
    vector<int> sol;
    find_any_solution(1, v.back(), c, x0, y0, g);
    vector<int> vnew = solution_n(vector<int>(v.begin(), v.end()-1), x0);
    for (auto i : vnew){
        sol.push_back(i);
    }
    sol.push_back(y0);
    return sol;
}

int main(){
    int a, b, c, x0, y0, g;
    while(true){
        cin >> a >> b >> c;
        find_any_solution(a, b, c, x0, y0, g);
        cout << x0 << " "
            << y0 << " "
            << g << endl;
    }
    return 0;
}
