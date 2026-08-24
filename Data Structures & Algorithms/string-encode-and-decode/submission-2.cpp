class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(string str : strs){
            int len = str.length();
            enc += to_string(len) + "#" + str;
        }

        return enc;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i< s.length()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }

            int len = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, len));

            i=len+j+1;
            
        }
        return res;
    }
};
