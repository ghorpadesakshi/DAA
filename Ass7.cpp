#include <bits/stdc++.h>

using namespace std;

int count(int coins[], int n, int sum)
{
   
    int cs[sum + 1] = {0}; 
    cs[0] = 1; 
    
    for (int i = 0; i < n; i++) { 
        for (int j = coins[i]; j <= sum; j++) { 
            cs[j] += cs[j - coins[i]]; 
        }
    }

    return cs[sum];
}


int main()
{
    int coins[] = {1, 2, 3}; 
    int n = 3; 
    int sum = 5; 
    cout << count(coins, n, sum) << endl; 
    return 0;
}
