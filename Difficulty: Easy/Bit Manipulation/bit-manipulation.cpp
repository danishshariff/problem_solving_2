//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
       int bit_check = (num & (1 << (i - 1))) != 0 ? 1 : 0;
        cout << bit_check << " ";  
        
        // Set the ith bit
        int bit_set = num | (1 << (i - 1));
        cout << bit_set << " ";  
        
        // Clear the ith bit
        int bit_clear = num & ~(1 << (i - 1));
        cout << bit_clear;  
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends