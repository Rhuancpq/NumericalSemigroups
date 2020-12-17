#include <math.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

set<int> sumSet(set<int> A, set<int> B, int max){
    set<int> res;
    for(auto a : A){
        for(auto b : B){
            if(a+b > max)
                break;
            else
                res.insert(a+b);
        }
    }

    return res;
}

void findMinimalSet(set<int> *C) {
    int m = *C->begin();
    if(m < pow((int) log2(C->size()), 4)){
        vector<int> aux;
        aux.push_back(m);
        for (int i = 1; i < m; i++){
            int g = -1;
            for (auto x : *C){
                if(x%m == i){
                    g = x;
                    break;
                }
            }

            if(g != -1){
                aux.push_back(g);
            }
        }
        *C = set<int>(aux.begin(), aux.end());
    }

    set<int> ss = sumSet(*C, *C, *C->rbegin());
    while (!ss.empty()){
        set<int> temp;
        set_difference(C->begin(), C->end(), ss.begin(), ss.end(),
                    inserter(temp, temp.end()));
        
        ss = sumSet(ss, temp, *temp.rbegin());
        *C = set<int>(temp);
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
    findMinimalSet(&C);
    cout << "Tamanho minimal: " << C.size() << endl;
    for(auto x : C)
        cout << x << " ";
    cout << endl;
    return 0;
}
