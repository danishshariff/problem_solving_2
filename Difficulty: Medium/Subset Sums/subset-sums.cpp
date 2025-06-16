class Solution {
  public:
  void subsetsumhelper(int ind, vector<int>& arr, vector<int>&ans, int sum){
      int n=arr.size();
      if(ind==n){
          ans.push_back(sum);
          return;
      }
      subsetsumhelper(ind+1, arr, ans,sum+arr[ind]);
      subsetsumhelper(ind+1,arr,ans,sum);
  }
    vector<int> subsetSums(vector<int>& arr) {
        // code here]
        vector<int> ans;
        subsetsumhelper(0,arr,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};