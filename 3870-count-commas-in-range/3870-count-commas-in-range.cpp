class Solution {
public:
    int countCommas(int n) {
        string str =to_string(n);
        int len=str.length();

        if(len<4) return 0;
        return (n-1000)+1;
    }
};