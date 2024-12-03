#include <bits/stdc++.h>
using namespace std;

// Function to check if all tasks can be completed 
// with 'tasksPerDay' tasks per day within 'days' days
bool isValid(int tasksPerDay, vector<int>& tasks, int days) {
    int totalDays = 0;
    for (int task : tasks) {
        totalDays += ceil((double)task / tasksPerDay);
        if (totalDays > days) return false; // Exceeds available days
    }
    return totalDays <= days;
}

// Function to find the minimum number of tasks to be done each day
int findMinTasks(vector<int>& tasks, int days) {
    int low = 1, high = *max_element(tasks.begin(), tasks.end());
    int minTasksPerDay = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if current `mid` is valid
        if (isValid(mid, tasks, days)) {
            minTasksPerDay = mid; // Store result
            high = mid - 1;       // Search in the lower half
        } else {
            low = mid + 1;        // Search in the upper half
        }
    }

    return minTasksPerDay;
}

// Driver Code
int main() {
    vector<int> tasks = {3, 4, 7, 15};
    int days = 10;

    cout << findMinTasks(tasks, days) << endl;

    return 0;
}
