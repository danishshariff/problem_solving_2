//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
// public:
//     int count(vector<int>& coins, int sum) {
//         int result = 0;
//         coinhelper(coins, sum, 0, result);
//         return result;
//     }

// private:
//     void coinhelper(vector<int>& coins, int sum, int index, int &count) {
//         if (sum == 0) {
//             count += 1;
//             return;
//         }
//         if (sum < 0) {
//             return;
//         }
//         for (int i = index; i < coins.size(); i++) {
//             coinhelper(coins, sum - coins[i], i, count);
//         }
//     }
// };

class Solution {
public:
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> memo(coins.size(), vector<int>(sum + 1, -1));
        return coinhelper(coins, sum, 0, memo);
    }

private:
    int coinhelper(vector<int>& coins, int sum, int index, vector<vector<int>>& memo) {
        if (sum == 0) {
            return 1;
        }
        if (sum < 0) {
            return 0;
        }
        if (index >= coins.size()) {
            return 0;
        }

        if (memo[index][sum] != -1) {
            return memo[index][sum];
        }

        int includeCoin = coinhelper(coins, sum - coins[index], index, memo);
        int excludeCoin = coinhelper(coins, sum, index + 1, memo);

        memo[index][sum] = includeCoin + excludeCoin;
        return memo[index][sum];
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends