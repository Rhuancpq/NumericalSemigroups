#include <math.h>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

void findMinimalSet(set<int> &C){
    auto y = C.begin();
    y++;
    unordered_map<int, bool> ht;
    for(auto x : C){
        ht[x] = true;
    }
    auto x = C.end;
    x--
    for(; x != y; x--){
        priority_queue<int> q;
        unordered_map<int, bool> pre;
        bool flag = false;
        q.push(*x);
        while(!flag and !q.empty()){
            int v = q.top();
            q.pop();
            if(pre[v])
                continue;
            pre[v] = true;
            
            for(auto i = C.begin(); *i < *x ; i++){
                int t = v-*i;

                if(t < 0)
                    break;

                if(t == 0){
                    flag = true;
                    break;
                }
                if(ht[t]){
                    flag = true;
                    break;
                }

                q.push(t);
            }
            
            if(flag){
                break;
                C.erase(x);
            }
        }
    }
}

int main(void) {
    return 0;
}
