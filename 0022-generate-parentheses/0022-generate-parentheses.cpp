class Solution {
public:
    void insert(int n ,vector<string> &s,string &st,int open,int close){
        if(st.size()==2*n){
            s.push_back(st);
            return ;
        }

        if(open==0|| open<n){
            open++;
            st+='(';
            insert(n,s,st,open,close);
            st.pop_back();
            open--;
        }
        if(close<open){
            close++;
            st+=')';
            insert(n,s,st,open,close);
            st.pop_back();
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        string st;

        insert(n,s,st,0,0);
        return s;
    }
};