#include <vector>
#include <unordered_map>
#include <cstring>
#include <iostream>
using namespace std;

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

int main(){
    vector<vector<vector<int>>> a = {
        {{ 1 }},
        {{ 2, 3 }},
        {{ 3, 4, 5 },
        { 2, 5 }},
        {{ 4, 5, 6, 7 },
        { 3, 5, 7 },
        { 3, 4 },
        { 2, 7 }},
        {{ 5, 6, 7, 8, 9 },
        { 4, 6, 7, 9 },
        { 4, 5, 7 },
        { 4, 5, 6 },
        { 3, 5 },
        { 3, 7, 8 },
        { 2, 9}}
    };
    for(int i = 0; i < a.size(); i++){
        cout << "Gen: " << i << endl;
        for(auto y : a[i]){
            cout << "Min gen: ";
            for(auto z : y){
                cout << z;
                if(*y.rbegin() == z)
                    cout << endl;
                else
                    cout << " ";
            }
            vector<unordered_map<int,int>> memo(y.size()+1);
            count(&y, y.size(), 10*i, &memo);
            for (int j = 0; j <= 10*i; j++){
                cout << "ds(" << j << ") = "
                << count(&y, y.size(), j, &memo) << endl;
            }
            cout << endl;
        }
    }
    return 0;
}