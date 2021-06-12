#include <math.h>
#include <vector>
#include <iostream>
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

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

vector<vector<int>> solution_n(vector<int> v, vector<int> c){
    if(v.size() == 2){
        int x0, y0, g;
        vector<vector<int>> sol;
        vector<int> tempa, tempb;
        find_any_solution(v.front(), v.back(), c.front(), x0, y0, g);
        for(auto ci : c){
            tempa.push_back(x0*ci/g);
            tempb.push_back(y0*ci/g);
        }
        tempa.push_back(v.back()/g); // /g
        tempb.push_back(v.front()*-1/g); // /g 
        sol.push_back(tempa);
        sol.push_back(tempb);
        return sol;
    }
    int x0, y0, g;
    vector<vector<int>> sol;
    vector<int> tempa, tempb;
    find_any_solution(1, v.back(), c.front(), x0, y0, g); // k_m*x + v[n]*y = c[0] 
    for(auto ci : c){
        tempa.push_back(x0*ci/g);
        tempb.push_back(y0*ci/g);
    }
    tempa.push_back(v.back()/g);
    tempb.push_back(-1); 
    vector<vector<int>> vnew = solution_n(vector<int>(v.begin(), v.end()-1), tempa);
    for (auto i : vnew){
        sol.push_back(i);
    }
    sol.push_back(tempb);
    return sol;
}

vector<vector<int>> solution_n(vector<int> v, int c){
    int x0, y0, g;
    vector<vector<int>> sol;
    vector<int> tempa, tempb;
    if(v.size() == 2){
        g = gcd(v.front(), v.back(), x0, y0);
        if (v.front() < 0) x0 = -x0;
        if (v.back() < 0) y0 = -y0;
        tempa.push_back(x0*c/g);
        tempb.push_back(y0*c/g);
        tempa.push_back(v.back()/g); // /g
        tempb.push_back(v.front()*-1/g); // /g 
        sol.push_back(tempa);
        sol.push_back(tempb);
        return sol;
    }
    find_any_solution(1, v.back(), c, x0, y0, g); // k_1*x + v_n*y = c 
    tempa.push_back(x0*c/g);
    tempa.push_back(v.back()/g); 
    tempb.push_back(y0*(c/g));
    tempb.push_back(-1);
    // tempa: k_1
    // v1 + v2 + ... + v_n = k_1
    vector<vector<int>> vnew = solution_n(vector<int>(v.begin(), v.end()-1), tempa);
    for (auto i : vnew){
        sol.push_back(i);
    }
    sol.push_back(tempb);
    return sol;
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
    vector<vector<int>> sol = solution_n(v, c);
    cout << sol.size() << endl;
    for (auto x : sol){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
