//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st; 
        int n = pre_exp.length();

  
        for (int i = n - 1; i >= 0; i--) {
      
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || 
                (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || 
                (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {
                st.push(string(1, pre_exp[i]));  
            } 

            else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string combine =  t1 + t2 + pre_exp[i];
                st.push(combine);
            }
        }

        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends