class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len=0;

        int pv =1;
        int n = s.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
             len++;
            else if( pv<=k)
            {
                k=k-pv;
                len++;
            }

            if(pv<=k){
                pv=pv*2;
            } 
        }

        return len;
    }
};