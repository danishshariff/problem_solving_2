class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int lar=-1;
        int slar=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>lar){
                slar=lar;
                lar=arr[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=lar &&  arr[i]>slar){
                slar=arr[i];
            }
        }
        return slar;
    }
};