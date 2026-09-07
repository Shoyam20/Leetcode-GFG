class Solution {
public:
    int M=1e9+7;
    vector<int> prev;
    int dp[20001];

    int func(int n)
    {
        if(n==0) return 1;

        if(dp[n]!=-1) return dp[n];

        int total=(2*func(n-1))%M;
        
        if(prev[n]!=0)
        {
            int dup=func(prev[n]-1);
            total=(total-dup+M)%M;
        }

        return dp[n]=total;

    }
    int distinctSubseqII(string s) {
        vector<int>lastseen(26,0);
        int n=s.size();
        prev.assign(n+1,0);
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            int ind=s[i-1]-'a';
            prev[i]=lastseen[ind];
            lastseen[ind]=i;
        }

        return (func(n)-1+M)%M;
    }
};