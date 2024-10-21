//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    // Function to find the floor of x
    int findFloor(vector<int> &v, int n, int x) {
        int low = 0, high = n - 1, ans = -1;

        // Binary search to find the floor of x
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid] <= x) {
                ans = v[mid];       // Potential answer
                low = mid + 1;      // Move right to find a larger candidate
            } else {
                high = mid - 1;     // Move left
            }
        }

        return ans; // Return -1 if no valid floor found
    }

    // Function to find the ceil of x
    int findCeil(vector<int> &v, int n, int x) {
        int low = 0, high = n - 1, ans = -1;

        // Binary search to find the ceil of x
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid] >= x) {
                ans = v[mid];       // Potential answer
                high = mid - 1;     // Move left to find a smaller candidate
            } else {
                low = mid + 1;      // Move right
            }
        }

        return ans; // Return -1 if no valid ceil found
    }

    // Function to get both floor and ceil of x
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int floor = findFloor(arr, n, x);
        int ceil = findCeil(arr, n, x);
        return {floor, ceil};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends