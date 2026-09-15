class Solution {
public:
    vector<vector<int>> t;
    bool ispalin(string &s ,int i , int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &s ,int k ,int i, int j)
    {
        if(i>=s.size() || j>=s.size())
            return 0;

        if(t[i][j]!=-1) 
            return t[i][j];
        if(ispalin(s,i,j))
        {
            int takeit=1+solve(s,k,j+1,j+k);
            int grow=solve(s,k,i,j+1);
            int slide=solve(s,k,i+1,j+1);
            return t[i][j]=max(takeit,max(grow,slide));
        }

        int grow=solve(s,k,i,j+1);
        int slide=solve(s,k,i+1,j+1);

        return t[i][j]=max(grow,slide);
    }
    int maxPalindromes(string s, int k) {
        int n =s.length();
        if(k==1) return n;
        t.assign(n+1,vector<int>(n+1,-1));

        return solve(s,k,0,k-1);
    }
};