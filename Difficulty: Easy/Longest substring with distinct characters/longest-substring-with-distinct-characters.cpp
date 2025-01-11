//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
  unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int start = 0; // Start of the current window
        
        for (int i = 0; i < s.length(); i++) {
            // If character is already in the map and within the current window
            if (lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= start) {
                // Move the start to the right of the previous occurrence
                start = lastIndex[s[i]] + 1;
            }
            
            // Update the last index of the current character
            lastIndex[s[i]] = i;
            
            // Update the maximum length of the substring
            maxLength = max(maxLength, i - start + 1);
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends