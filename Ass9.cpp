#include <bits/stdc++.h>
using namespace std;

int m[2000][2000]; // Memoization table

int sub(int a[], int n, int sum) {   
    if (sum == 0) // Base case: a sum of 0 can always be achieved with an empty subset
        return 1;
        
    if (n <= 0) // No items left to check
        return 0;

    if (m[n][sum] != -1) // If already computed, return the stored result
        return m[n][sum];
  
    if (a[n - 1] > sum) // If the current element is greater than the sum, skip it
        return m[n][sum] = sub(a, n - 1, sum);
    else { // Check both possibilities: including or excluding the current element
        return m[n][sum] = sub(a, n - 1, sum) || 
                           sub(a, n - 1, sum - a[n - 1]);
    }
}

int main() {
    memset(m, -1, sizeof(m)); // Initialize the memoization table
    int n = 5;  
    int a[] = {1, 5, 3, 7, 4}; // The array of elements
    int sum = 92; // The target sum

    if (sub(a, n, sum)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
