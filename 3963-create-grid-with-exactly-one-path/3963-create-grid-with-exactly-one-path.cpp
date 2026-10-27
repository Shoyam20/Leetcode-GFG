class Solution {
public:
    
    vector<string> createGrid(int m, int n) {
        string t(n,'.');
        string s=string(n-1,'#') + '.';
        vector<string> str;
        str.push_back(t);
        for(int i =1;i<m;i++){
            
            str.push_back(s);
        }
        return str;
    }
};



