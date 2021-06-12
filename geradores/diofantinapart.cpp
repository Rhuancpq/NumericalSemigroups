#include <math.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>

using namespace std;

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

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

vector<int> solution_n(vector<int> v, int c){
    // this version won't work with all cases, only ones when all 
    // neighbor pairs are co-primes 
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

vector<int> solution_part(int d, vector<int> v, int c, int &dn, int &k){
    int x0, y0, g;
    g = gcd(abs(d), abs(*v.begin()), x0, y0);
    if (d < 0) x0 = -x0;
    if (*v.begin() < 0) y0 = -y0;
    vector<int> res;
    if(v.size() == 1){
        // base case
        dn = g;
        res.push_back(y0*c/dn);
        k = x0;
        return res;
    }
    res = solution_part(g, vector<int>(v.begin()+1, v.end()), c, dn, k);
    res.push_back(y0*k*c/dn);
    k *= x0;
    return res;
}

vector<int> solution_part(vector<int> v, int c){
    int x0, y0, g, dn, k;
    g = gcd(abs(*v.begin()), abs(*(v.begin()+1)), x0, y0);
    if (*v.begin() < 0) x0 = -x0;
    if (*(v.begin()+1) < 0) y0 = -y0;
    vector<int> res;
    if(v.size() == 2){
        res.push_back(y0*c/g);
        res.push_back(x0*c/g);
        return res;
    }
    res = solution_part(g, vector<int>(v.begin()+2, v.end()), c, dn, k);
    res.push_back(y0*k*c/dn);
    res.push_back(x0*k*c/dn);
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int c;
    cin >> c;
    vector<int> sol = solution_part(v, c);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cout << sol[n-i-1] << " ";
        sum += v[i]*sol[n-i-1];
    }
    cout << endl;
    cout << sum << endl; 
    return 0;
}
