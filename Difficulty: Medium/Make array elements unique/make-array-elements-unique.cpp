//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
sort(arr.begin(), arr.end());
        
        int next_unique = arr[0];  // Start with the first element
        int operations = 0;
        
        // Step 2: Traverse the array to make all elements unique
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= next_unique) {
                // If current element is not greater than the previous unique value
                operations += next_unique + 1 - arr[i];  // Increment to make it unique
                next_unique += 1;  // Update the next available unique value
            } else {
                next_unique = arr[i];  // If it's already unique, update the next available unique value
            }
        }
        
        return operations;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends