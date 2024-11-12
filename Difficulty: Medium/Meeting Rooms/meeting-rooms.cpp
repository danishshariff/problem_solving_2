//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Step 1: Sort meetings by start time
        sort(arr.begin(), arr.end());
        
        // Step 2: Check for any overlapping meetings
        for (int i = 0; i < arr.size() - 1; i++) {
            // If the current meeting ends after the next meeting starts, they overlap
            if (arr[i][1] > arr[i + 1][0]) {
                return false;
            }
        }
        
        // If no overlaps, return true
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends