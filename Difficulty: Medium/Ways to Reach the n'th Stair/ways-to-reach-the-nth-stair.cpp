//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWaysMemo(int n, vector<int>& memo) {
        
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (memo[n] != -1) return memo[n]; 

        
        memo[n] = countWaysMemo(n - 1, memo) + countWaysMemo(n - 2, memo);
        return memo[n];
    }

    int countWays(int n) {
        vector<int> memo(n + 1, -1); 
        return countWaysMemo(n, memo);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends