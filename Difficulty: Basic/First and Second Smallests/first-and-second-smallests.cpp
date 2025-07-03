class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int small=INT_MAX;
        int ssmall=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<small){
                ssmall=small;
                small=arr[i];
            }
            else if(arr[i]>small && arr[i]<ssmall){
                ssmall=arr[i];
            }
        }
        if(ssmall==INT_MAX){
            return{-1,-1};
        }
  
          return {small,ssmall};
    }
};