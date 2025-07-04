class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int count=0;
        int i=0;
        int j=0;
        unordered_map<int,int> mpp;
        while(j<arr.size()){
            mpp[arr[j]]++;
            while(i<arr.size() && mpp.size()>k){
                mpp[arr[i]]--;
                if(mpp[arr[i]]==0){
                    mpp.erase(arr[i]);
                }
                i++;
            }
            if(mpp.size()<=k){
                count+=j-i+1;
            }
            j++;
        }
        return count;
    }
};