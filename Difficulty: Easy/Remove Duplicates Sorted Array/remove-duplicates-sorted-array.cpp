class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        unordered_set<int> st;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
          if(st.find(arr[i])==st.end()){
              st.insert(arr[i]);
              ans.push_back(arr[i]);
          }
        }
        
       
        return ans;
    }
};