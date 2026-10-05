class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int score=0;
        vector<int> v;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){
                v.push_back(score);
                score=0;
            }
            else{
                if(s[i-1]=='('){
                    score=v.back()+1;
                }else{
                    score=v.back()+(score*2);
                }
                v.pop_back();
            }
        }
        
        // int x=v.back();

        return score;
    }
};