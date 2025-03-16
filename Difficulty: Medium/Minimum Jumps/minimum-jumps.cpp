//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        if (arr.size() <= 1) return 0;
        if (arr[0] == 0) return -1; 
        int jumps = 0;      
        int l = 0;         
        int r = 0;         

        while (r < arr.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + arr[i]); 
                if (farthest >= arr.size() - 1) { 
                    return jumps + 1;
                }
            }
            
            if (farthest <= r) return -1; 
            l = r + 1; 
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends