//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string concat=s1;
        int cnt=1;
        while(concat.find(s2)==string::npos){
            concat+=s1;
            cnt++;
            if (concat.size() > s2.size()+s1.size() *2){
                return -1; 
            }
            
        }
        return cnt;
     

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends