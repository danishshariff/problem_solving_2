//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
// public:
//     int minCoins(vector<int>& coins, int sum) {
//         int cnt = INT_MAX; // Initialize to a large value
//         count(0, coins, sum, 0, cnt); // Start the recursion
//         return cnt == INT_MAX ? -1 : cnt; // If no solution, return -1
//     }

//     void count(int ind, vector<int>& coins, int sum, int currentCnt, int& cnt) {
//         // Base case: if sum becomes 0, update cnt with the minimum value
//         if (sum == 0) {
//             cnt = min(cnt, currentCnt);
//             return;
//         }

//         // Base case: if index exceeds bounds or sum goes negative
//         if (ind >= coins.size() || sum < 0) {
//             return;
//         }

//         // Include the current coin
//         count(ind, coins, sum - coins[ind], currentCnt + 1, cnt);

//         // Exclude the current coin and move to the next
//         count(ind + 1, coins, sum, currentCnt, cnt);
//     }
// };

class Solution {
public:
    int minCoins(vector<int>& coins, int sum) {
        // Memoization table: initialize with -1 (uncomputed states)
        vector<vector<int>> memo(coins.size(), vector<int>(sum + 1, -1));
        
        int cnt = solve(0, coins, sum, memo);
        return cnt == INT_MAX ? -1 : cnt; // If no solution, return -1
    }

    int solve(int ind, vector<int>& coins, int sum, vector<vector<int>>& memo) {
        // Base case: if the sum is zero, no coins are needed
        if (sum == 0) return 0;

        // Base case: if index exceeds bounds or sum becomes negative
        if (ind >= coins.size() || sum < 0) return INT_MAX;

        // Check the memoization table to avoid redundant computations
        if (memo[ind][sum] != -1) return memo[ind][sum];

        // Recursive case: choose to include or exclude the current coin
        int include = INT_MAX;
        if (sum >= coins[ind]) {
            int result = solve(ind, coins, sum - coins[ind], memo);
            if (result != INT_MAX) include = result + 1; // Add current coin
        }

        int exclude = solve(ind + 1, coins, sum, memo);

        // Memoize the result for the current state
        memo[ind][sum] = min(include, exclude);
        return memo[ind][sum];
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends