//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> result;
    
    void solve(int row, int n, vector<int>& board, vector<int>& cols, vector<int>& d1, vector<int>& d2) {
        if (row == n) { 
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] || d1[row + col] || d2[row - col + n - 1]) continue; 
            
            board[row] = col + 1;  
            cols[col] = d1[row + col] = d2[row - col + n - 1] = 1;
            
            solve(row + 1, n, board, cols, d1, d2);
            
            
            cols[col] = d1[row + col] = d2[row - col + n - 1] = 0;
        }
    }

    vector<vector<int>> nQueen(int n) {
        result.clear();
        vector<int> board(n, 0);
        vector<int> cols(n, 0), d1(2 * n, 0), d2(2 * n, 0);
        solve(0, n, board, cols, d1, d2);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends