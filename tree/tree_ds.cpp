#include <vector>
#include <utility>
#include <map>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void print_vec (vector<pair<int, int>> v){
    cout << "[ ";
    for(auto x : v){
        cout << "{" << x.first
        << "," << x.second << (x == *v.rbegin() ? "} ]" : "}, ");
    }
    cout << endl;
}

int main(){
    vector<pair<int, int>> father = {
{0,1},
{1,0},
{2,0},
{3,0},
{4,1},
{5,1},
{6,1},
{7,1},
{8,2},
{9,2}};
    vector<vector<pair<int, int>>> sons = {{
{0,1},
{1,0},
{2,0},
{3,0},
{4,1},
{5,1},
{6,1},
{7,0},
{8,2},
{9,2},
{10,3},
{11,3},
{12,4}
},{
{0,1},
{1,0},
{2,0},
{3,0},
{4,1},
{5,1},
{6,0},
{7,1},
{8,2},
{9,2},
{10,3},
{11,3},
{12,3}
},{
{0,1},
{1,0},
{2,0},
{3,0},
{4,1},
{5,0},
{6,1},
{7,1},
{8,2},
{9,1},
{10,2},
{11,2},
{12,3}
},{
{0,1},
{1,0},
{2,0},
{3,0},
{4,0},
{5,1},
{6,1},
{7,1},
{8,1},
{9,1},
{10,2},
{11,2},
{12,3}
}};

    cout << "Pai:" << endl;
    print_vec(father);

    cout << "\nFilhos: " << endl;
    for(auto x : sons)
        print_vec(x);
    cout << endl;

    for(auto x : sons){
        vector<pair<int,int>> itsec, dif;
        set_intersection(father.begin(), father.end(),
        x.begin(), x.end(), inserter(itsec, itsec.end()));
        set_difference(x.begin(), x.end(),
        father.begin(), father.end(), inserter(dif, dif.end()));

        cout << "Em comum: " << endl;
        print_vec(itsec);

        cout << "Exclusivos do filho: " << endl;
        print_vec(dif);
        cout << endl;
    }

    return 0;
}