//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
 unordered_map<int, int> freq; // Map to store the frequency of elements
        
        // First, store the frequency of each element in the array
        for (int num : arr) {
            freq[num]++;
        }
        
        int count = 0;

        // Now, iterate over the array to calculate pairs
        for (int num : arr) {
            int complement = target - num; // Find the complement for the target

            // Check if the complement exists in the map
            if (freq.find(complement) != freq.end()) {
                count += freq[complement]; // Add the frequency of the complement
                
                // If num and complement are the same, avoid double-counting the same element
                if (num == complement) {
                    count--;
                }
            }
        }

        // Since each pair is counted twice, divide the total count by 2
        return count / 2;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends