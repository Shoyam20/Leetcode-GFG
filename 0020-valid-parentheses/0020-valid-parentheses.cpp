class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(' || ch=='[' || ch=='{')
            {
                st.push(ch);
            }
            else{
                char t;
                if(st.size()!=0)
                    t=st.top();
                else 
                    return false;
                if((t=='('&& ch==')' )|| (t=='['&& ch==']' )|| (t=='{' && ch=='}'))
                    st.pop();
                else return false;
            }




        }
        if(st.size()==0) return true;
        return false;
    }
};