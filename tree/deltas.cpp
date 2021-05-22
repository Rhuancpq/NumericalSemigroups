#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <iostream>
using namespace std;

unordered_map<int, int> compute_delta(set<int> G, set<int> gen){
    int g = G.size();
    unordered_map<int, int> delta;
    for(auto x : G)
        delta[x] = 0;
    delta[0] = 1;
    for(auto x : gen)
        delta[x] = 1;

    for (int i = 1; i <= 3*g; i++){
        if(G.count(i) == 1 || gen.count(i) == 1){
            continue;
        }

        for (int j = 1; j <= i/2; j++){
            if(delta[j] and delta[i-j])
                delta[i]++;
        }

        if(delta[i] != 0){
            delta[i]++;
        }
    }
    
    return delta;
}

int main(){
    set<int> G = { 1, 3, 5};
    set<int> gen = {2, 7};

    unordered_map<int, int> delta = compute_delta(G, gen);
    map<int, int> res(delta.begin(), delta.end());
    for(auto x: res){
        cout << "X: " << x.first
        << " | d(X): " << x.second << endl;
    }
    return 0;
}