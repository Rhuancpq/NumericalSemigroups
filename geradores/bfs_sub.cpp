#include <math.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, bool> removeMultiples(set<int> *C){ 
    int max = *C->rbegin();
    unordered_map<int, bool> ht;
    for(auto x : *C)
        ht[x] = true;
    for(auto x : *C){
        for (int i = x*2; i <= max; i += x){ 
            if(ht[i])
                C->erase(i);
            ht[i] = true;
        }
    }
    return ht;
}

void findAperry(set<int> *C){
    int m = *(C->begin());
    vector<int> ap(m);
    int count = 0;
    for(auto x : *C){
        int t = x%m;
        if(!ap[t]){
            ap[t] = x;
            count++;
        }
        if(count == m)
            break;
    }
    *C = set<int>(ap.begin(), ap.end());
    C->erase(0);
}

bool testMinimality(set<int> *C, int x, unordered_map<int, bool>* ht){
    set<int, greater<int>> q;
    unordered_map<int, bool> pre;
    q.insert(x);
    while(!q.empty()){
        int v = *q.begin();
        q.erase(q.begin());
        if(pre[v])
            continue;
        pre[v] = true;
        
        for(auto i = C->begin(); *i < x ; i++){
            int t = v-*i;

            if(t < *C->begin())
                break;
            
            if((*ht)[t] or t == 0){
                return false;
            }
            
            if(!pre[t])
                q.insert(t);
        }
    }
    return true;
}

void findMinimalSet(set<int> *C) {
    auto y = C->begin();
    unordered_map<int, bool> ht = removeMultiples(C);
    auto x = C->end();
    x--;
    while(x != y) {
        set<int, greater<int>> q;
        unordered_map<int, bool> pre;
        q.insert(*x);
        bool res = testMinimality(C, *x, &ht);
        x--;
        if(!res){
            auto r = x;
            C->erase(++r);
        }
    }
}

int main(void) {
    set<int> C;
    int qtd;
    cin >> qtd;
    for (int i = 0; i < qtd; i++){
        int x;
        cin >> x;
        C.insert(x);
    }
    cout << "Tamanho inicio: " << C.size() << endl;
    cout << "Multiplicidade: " << *C.begin() << endl;
    findAperry(&C);
    cout << "Tamanho após obter aperry: " << C.size() << endl;
    if(*C.begin() == 0){
        cout << "Caso de teste ruim" << endl;
        return 0;
    }
    findMinimalSet(&C);
    cout << "Tamanho minimal: " << C.size() << endl;
    for(auto x : C)
        cout << x << " ";
    cout << endl;
    return 0;
}
