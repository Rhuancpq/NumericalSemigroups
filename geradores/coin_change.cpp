#include <math.h>
#include <vector>
#include <set>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

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

int count( const vector<int> *S, int m, int n,
vector<unordered_map<int,int>>* memo) {

    int r;

    if((*memo)[m][n] == 0){
        int table[n+1];

        memset(table, 0, sizeof(table)); 

        table[0] = 1; 

        for(int i=0; i<m; i++) 
            for(int j=(*S)[i]; j<=n; j++) 
                table[j] += table[j] > 2 ? 0 : table[j-(*S)[i]];
        
        r = table[n];
        (*memo)[m][n] = r;
    }else
        r = (*memo)[m][n];

    return r; 
} 

void findMinimalSet(set<int> *C) {
    auto y = C->begin();
    auto x = C->end();
    x--;
    vector<int> v(C->begin(), C->end());
    vector<unordered_map<int,int>> memo(v.size()+1);
    while(x != y) {
        int res = count(&v, v.size(), *x, &memo);
        x--;
        if(res != 1){
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
