//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int linearsearch(vector<int>& a, int num){
         for(int i=0;i<a.size();i++){
             if(a[i]==num){
                 return true;
                 
             }
         }
         return false;
     }
    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(vector<int>& arr) {
        // Your code here
        int longest=1;
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            int cnt=1;
            while(linearsearch(arr,x+1)==true){
                x+=1;
                cnt+=1;
            }
        longest=max(cnt,longest);
        }
        
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
        int res = ob.findLongestConseqSubseq(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends