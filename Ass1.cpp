#include<iostream>
using namespace std;

int main() {
    int n, a[10];
    int count = 0;

    cout << "Enter the size of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] == 0) {
            if(mid == 0 || a[mid - 1] == 1) {  // Corrected condition
                count = n - mid;
                break;
            } else {
                high = mid - 1;
            }
        } else {
            low = mid + 1;
        }
    }

    if(count == 0) {
        cout << "Zero not present" << endl;
    } else {
        cout << "Number of zeros are = " << count << endl;
    }

    return 0;
}