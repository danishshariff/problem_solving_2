//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
 //{ Driver Code Starts
// Initial template for C++

    // Find the smallest element greater than or equal to x in a sorted row
    int findCeil(vector<int> &v, int x) {
        int low = 0, high = v.size() - 1, ans = v.size();

        // Binary search to find the ceil of x in a sorted row
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (v[mid] > x) {
                ans = mid;         // Store potential answer (index of ceil)
                high = mid - 1;    // Move left to find a smaller candidate
            } else {
                low = mid + 1;     // Move right
            }
        }

        return ans; // Returns the count of elements less than x in this row
    }
    
    // Count the number of elements less than or equal to x in all rows
    int smallcount(vector<vector<int>>& mat, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += findCeil(mat[i], x);
        }
        return cnt;
    }
    
    // Find the median of the matrix
    int median(vector<vector<int>> &matrix, int n, int m) {
        int low = INT_MAX;
        int high = INT_MIN;
        
        // Find the global minimum and maximum elements in the matrix
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }
        
        int req = (n * m) / 2;
        
        // Binary search on the matrix range
        while (low <= high) {
            int mid = (low + high) / 2;
            int smalleq = smallcount(matrix, n, m, mid);
            
            if (smalleq <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
}

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends