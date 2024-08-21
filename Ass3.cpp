#include<iostream>
using namespace std;

// Function to count trailing zeros in factorial of a number
int countTrailingZeros(int x) {
    int count = 0;
    for (int i = 5; x / i >= 1; i *= 5) {
        count += x / i;
    }
    return count;
}

// Function to find the smallest number with at least n trailing zeros in factorial
int findSmallestNumber(int n) {
    if (n == 0) return 0; // 0! = 1, which has 0 trailing zeros

    int low = 0;
    int high = 5 * n;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros >= n) {
            result = mid;
            high = mid - 1; // Look for a smaller number in the left half
        } else {
            low = mid + 1;  // Look in the right half
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeros: ";
    cin >> n;

    int result = findSmallestNumber(n);
    cout << "The smallest number whose factorial has at least " << n << " trailing zeros is: " << result << endl;

    return 0;
}