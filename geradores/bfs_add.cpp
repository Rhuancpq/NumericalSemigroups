#include <math.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

void findAperry(set<int> *C){
    int m = *(C->begin());
    vector<int> ap(m);
    for(auto x : *C){
        int t = x%m;
        if(!ap[t])
            ap[t] = x;
    }
    *C = set<int>(ap.begin(), ap.end());
    C->erase(0);
}

void findMinimalSet(set<int> *C){
    unordered_map<int, bool> ht;
    for(auto x : *C){
        ht[x] = true;
    }
    set<int, greater<int>> q;
    for (auto x : *C){
        q.insert(x);
    }
    unordered_map<int, bool> pre;
    while(!q.empty()){
        int v = *q.begin();
        q.erase(q.begin());
        if(pre[v])
            continue;
        pre[v] = true;

        for(auto x : *C){
            int t = v+x;

            if(t > *C->rbegin())
                break;

            if(ht[t])
                C->erase(t);

            if(!pre[t])
                q.insert(t);
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
