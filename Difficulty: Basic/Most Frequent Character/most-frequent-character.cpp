

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        int arr[26]={0};
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int num=0;
            num=ch-'a';
            arr[num]++;
        }
        int maxi=-1;
        int ans=0;
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                ans=i;
                maxi=arr[i];
            }
        }
        char finalans='a'+ans;
        return finalans;
    }
};