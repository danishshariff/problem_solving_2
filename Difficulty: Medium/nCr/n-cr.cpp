//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
using namespace std;

class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r; 
        long long result = 1;

        for (int i = 0; i < r; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends