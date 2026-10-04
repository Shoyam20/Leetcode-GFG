class Solution {
public:
    int dp[101][101];
    bool solve(int i ,string s ,int open){
        if(i==s.size()) return open==0;

        bool isvalid=false;


        if(dp[i][open]!=-1){
            return dp[i][open];
        }
        if(s[i]=='(')
        {
            isvalid|=solve(i+1,s,open+1);

        }else if(s[i]=='*'){
            isvalid|=solve(i+1,s,open+1);
            isvalid|=solve(i+1,s,open);
            if(open>0)
                isvalid|=solve(i+1,s,open-1);
        }
        else if(open>0)isvalid|=solve(i+1,s,open-1);


        return dp[i][open]=isvalid;
    }
    bool checkValidString(string s) {

        memset(dp,-1,sizeof(dp));

        return solve(0,s,0);
    }
};