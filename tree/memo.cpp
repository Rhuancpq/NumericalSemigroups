#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, int> count(vector<int> S, int m, int n )         
{         
 // table[i] will be storing the number of solutions for         
 // value i. We need n+1 rows as the table is constructed         
 // in bottom up manner using the base case (n = 0)         
 unordered_map<int, int> table;         
 // Initialize all table values as 0         
 for (int i = 0; i <= n; i++)
    table[i] = 0;
        
 // Base case (If given value is 0)         
 table[0] = 1;         
 // Pick all coins one by one and update the table[] values         
 // after the index greater than or equal to the value of the         
 // picked coin         
 for(int i=0; i<m; i++)         
 for(int j=S[i]; j<=n; j++)         
 table[j] += table[j-S[i]];

 return table;         
}

int count2(vector<int> S, int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];
     
    // Fill the enteries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int main(){
    //vector<int> s = { 2, 4, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    unordered_map<int, int> t1 = count(s, s.size(), 20);
    unordered_map<int, int> t2 = count(s, s.size(), 10);
    unordered_map<int, int> t3 = count(s, 10, 10);
    for (int i = 0; i < 11; i++){
        cout << "Suíte: i = " << i << endl;
        cout << "Controle = " << count2(s, s.size(), i) << endl;
        cout << "Table 1 (m = #s, n = 20): "<< t1[i] << endl;
        cout << "Table 2 (m = #s, n = 10): "<< t2[i] << endl;
        cout << "Table 3 (m = 10, n = 10): "<< t3[i] << endl;
        cout << endl;
    }
    
    return 0;
}