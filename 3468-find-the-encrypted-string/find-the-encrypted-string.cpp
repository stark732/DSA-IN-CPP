class Solution {
public:
    string getEncryptedString(string s, int k) {
        string st = "";
        int len = s.size();

        for(int i = 0; i < len ; i++){
            int newindex = ( i + k) % len;

            st += s[newindex];
        }
        return st;
    }
};