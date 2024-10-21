//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the floor of x
    int findFloor(vector<long long> &v, long long n, long long x) {
        int low = 0, high = n - 1, ans = -1;

        // Binary search to find the floor of x
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid] <= x) {
                ans = mid;       // Potential answer
                low = mid + 1;   // Move right to find a larger candidate
            } else {
                high = mid - 1;  // Move left
            }
        }

        return ans; // -1 if no floor exists
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends