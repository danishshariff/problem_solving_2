//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        string result = "1"; // Starting string
        
        for (int i = 1; i < n; i++) {
            string temp = "";
            int count = 1;
            
            // Go through the current result string
            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++; // same digit
                } else {
                    // Add count and digit to temp
                    temp += to_string(count) + result[j - 1];
                    count = 1; // reset count for new digit
                }
            }
            
            // Add the last group
            temp += to_string(count) + result.back();
            result = temp; // update result for next round
        }
        
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
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends