class Solution {
public:
    int n;
    int maxlen;

    unordered_set<string> st;


    void solve(int i , string &s, int count,string &curr){
        if(count<0) return ;
        if(i==n){
            if(count==0){
                if(maxlen<curr.length()){
                    maxlen=curr.length();
                    st.clear();
                }
                if(maxlen==curr.length())
                    st.insert(curr);
            }
            return ;
        }

        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(i+1,s,count,curr);
            curr.pop_back();
            return;
        }
        else{
            curr.push_back(s[i]);

            solve(i+1,s,count+(s[i]=='('? 1: -1),curr);
            curr.pop_back();
            solve(i+1,s,count,curr);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        maxlen=0;
        st.clear();
        string curr="";
        solve(0,s,0,curr);

        return vector<string> (st.begin(),st.end());
    }
};