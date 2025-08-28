class Solution {
  public:
    string modify(string& s) {
        // code here.
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                res+=s[i];
            }
        }
        return res;
    }
};