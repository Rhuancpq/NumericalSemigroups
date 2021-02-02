#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v(t);
    for(int i = 0; i < t; i++)
        cin >> v[i];
    int n = *min_element(v.begin(), v.end());

    set<int> queue, res;
    map<int, bool> h;
    vector<bool> f(n-1);
    vector<set<int>> ap(n);
    for(auto x : v){
        ap[x%n].insert(x);
        f[x%n] = false;
        queue.insert(x);
    }
    vector<int> ap_f;

    while(!queue.empty()){
        int x = *queue.begin();
        queue.erase(queue.begin());

        if(h[x] == true)
            continue;
        h[x] = true;

        ap[x%n].insert(x);
        int l = 1;
        for(int i = 1; i < n; i++){
            if(ap[i].empty())
                continue;
            else
                f[i-1] = true;
            
            l += f[i-1];
            int y = *ap[i].begin();
            if(*ap[(x+y)%n].begin() > x+y || *ap[(x+y)%n].begin() == 0)
                queue.insert(x+y);
            else
                h[x+y] = true;
        }
        
        if(l == n){
            for(auto x : ap){
                ap_f.push_back(*x.begin());
            }
            ap_f[0] = 0;
            break;
        }
    }

    for(auto x : ap_f){
        cout << x << " ";
    }
    cout << endl;
}