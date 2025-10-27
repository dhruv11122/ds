// Implement the binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary Search function
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  

        if (arr[mid] == target)
            return mid;              // Target found
        else if (arr[mid] < target)
            left = mid + 1;          // Search right half
        else
            right = mid - 1;         // Search left half
    }

    return -1; 
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}