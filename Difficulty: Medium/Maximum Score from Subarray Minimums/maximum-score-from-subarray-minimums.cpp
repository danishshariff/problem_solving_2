//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        
        // Early return if there are fewer than 2 elements
        if (n < 2) {
            return 0;
        }

        int maxSum = INT_MIN;
        
        // Iterate through the array, checking sums of adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            int sum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends