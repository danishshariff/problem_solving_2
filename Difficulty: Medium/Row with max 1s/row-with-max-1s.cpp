//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  
    // Function to find the index of the first 1 in a sorted row
    int lowerbound(vector<int> &v, long long n, long long x) {
        int low = 0, high = n - 1;
        int ans = n;  // Set ans to n initially, to handle cases where no 1 is found

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid] >= x) {
                ans = mid;     // Potential answer (position of the first 1)
                high = mid - 1; // Move left to find an earlier 1
            } else {
                low = mid + 1;  // Move right if v[mid] < x
            }
        }

        return ans; // Returns index of first 1 or n if no 1 exists
    }

    // Function to find the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxOnes = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int firstOneIndex = lowerbound(arr[i], m, 1);
            int cnt_ones = m - firstOneIndex; // Number of 1s in the row

            if (firstOneIndex < m && cnt_ones > maxOnes) { // Check for rows with 1s
                maxOnes = cnt_ones;
                index = i;
            }
        }

        return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends