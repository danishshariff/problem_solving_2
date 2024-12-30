//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
      if (arr.empty()) return 0; // Handle edge case: empty array

        // Sort the array
        sort(arr.begin(), arr.end());

        int longest = 1; // At least one element in a sequence
        int currentStreak = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                // Skip duplicates
                continue;
            } else if (arr[i] == arr[i - 1] + 1) {
                // If consecutive, increment the current streak
                currentStreak++;
            } else {
                // Reset streak when the sequence breaks
                longest = max(longest, currentStreak);
                currentStreak = 1;
            }
        }

        // Final check for the last streak
        longest = max(longest, currentStreak);

        return longest;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends