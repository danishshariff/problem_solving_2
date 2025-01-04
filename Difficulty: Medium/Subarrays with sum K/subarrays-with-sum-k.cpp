//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int, int> prefixSumCount;
        int count = 0;
        int currentPrefixSum = 0;
        
        // Initialize the map with prefix sum 0 having 1 count
        prefixSumCount[0] = 1;
        
        // Traverse through the array
        for (int num : arr) {
            // Update the current prefix sum
            currentPrefixSum += num;
            
            // If the (currentPrefixSum - k) exists in the map, it means we found a subarray with sum = k
            if (prefixSumCount.find(currentPrefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentPrefixSum - k];
            }
            
            // Update the frequency of the current prefix sum
            prefixSumCount[currentPrefixSum]++;
        }
        
        return count;
    }
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends