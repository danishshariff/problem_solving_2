//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Sort the string to ensure permutations are generated in lexicographical order
        sort(s.begin(), s.end());
        vector<string> result;

        // Use do-while loop to generate all permutations
        do {
            result.push_back(s);
        } while (next_permutation(s.begin(), s.end()));

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends