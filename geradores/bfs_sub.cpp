#include <math.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, bool> removeMultiples(set<int> *C){ // does it really work?
    int max = *C->rbegin();
    unordered_map<int, bool> ht;
    for(auto x : *C)
        ht[x] = true;
    for(auto x : *C){
        for (int i = x*2; i <= max; i += x){ // otimizar isso e pensar em usar mod no lugar
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
    for(auto x : *C){
        int t = x%m;
        if(!ap[t])
            ap[t] = x;
    }
    set<int> C_new;
    for (auto x : ap)
        C_new.insert(x);
    *C = set<int>(C_new);
}

void findMinimalSet(set<int> *C) {
    auto y = C->begin();
    unordered_map<int, bool> ht = removeMultiples(C);
    auto x = C->end();
    x--;
    while(x != y) {
        set<int, greater<int>> q;
        unordered_map<int, bool> pre;
        bool flag = false;
        q.insert(*x);
        while(!flag and !q.empty()){
            int v = *q.begin();
            q.erase(q.begin());
            if(pre[v])
                continue;
            pre[v] = true;
            
            for(auto i = C->begin(); *i < *x ; i++){
                int t = v-*i;

                if(t < 0)
                    break;

                if(t == 0){
                    flag = true;
                    break;
                }
                if(ht[t]){
                    flag = true;
                    continue;
                }
                
                if(!pre[t])
                    q.insert(t);
            }
            
            if(flag){
                break;
            }
        }
        x--;
        if(flag){
            auto r = x;
            r++;
            C->erase(r);
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
