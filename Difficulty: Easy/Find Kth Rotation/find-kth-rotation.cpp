//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        
        // If the array is not rotated at all
        if (arr[low] <= arr[high]) {
            return 0;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is the smallest element (pivot point)
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return mid;
            }
            
            // Check if the element after mid is the smallest element
            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) {
                return mid + 1;
            }

            // If the left half is sorted, the pivot must be in the right half
            if (arr[low] <= arr[mid]) {
                low = mid + 1;
            } 
            // If the right half is sorted, the pivot must be in the left half
            else {
                high = mid - 1;
            }
        }
        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends