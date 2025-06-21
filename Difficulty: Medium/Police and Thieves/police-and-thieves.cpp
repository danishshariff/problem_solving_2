class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
    //     int count=0;
    //     int n=arr.size();
    //     vector<bool> caught(n,false);
    //     for(int i=0;i<n;i++){
    //       if(arr[i]=='P'){
    //           int left=max(0, i - k);
    //           int right=min(n - 1, i + k);// to avoid out of bounds
    //           for(int j=left;j<=right;j++){
    //               if(arr[j]=='T' && !caught[j]){
    //                   caught[j]=true;
    //                   count++;
    //                   break;
    //               }
    //           }
    //       }
    //     }
    //     return count;
    // }
    
    //optimal;
    
    int n=arr.size();
    int count=0;
    vector<int> thieves;
    vector<int> police;
    for(int i=0;i<n;i++){
        if(arr[i]=='P'){
            police.push_back(i);
        }
        else{
            thieves.push_back(i);
        }
    }
    
    int i=0;
    int j=0;
    while(i<police.size() && j<thieves.size()){
        if(abs(police[i]-thieves[j])<=k){
            count++;
            i++;
            j++;
        }
        else if(thieves[j]<police[i]){
            j++;
        }
        else{
            i++;
        }
    }
    return count;
    }
};