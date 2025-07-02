class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int i=0;
        int j=0;
        int n=arr.size();
        int ans=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[arr[j]]++;
            if(mpp.size()>2){
                while(i<n && mpp.size()>2){
                    mpp[arr[i]]--;
                    if(mpp[arr[i]]==0){
                        mpp.erase(arr[i]);
                    }
                    i++;
                }
            }
            if(mpp.size()<=2){
                ans=max(ans,j-i+1);
            }
                j++;
        }
        return ans;
    }
};