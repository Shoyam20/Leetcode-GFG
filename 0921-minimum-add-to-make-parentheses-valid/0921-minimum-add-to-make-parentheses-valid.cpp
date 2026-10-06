class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;

        stack<char>st;

        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];

            if(ch=='('){
                st.push(ch);
            }
            else{
                if(!st.empty()&&ch==')' && st.top()=='(')
                {
                    st.pop();
                }
                else{
                    count++;
                }
            }
        }
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};