class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for(auto i : asteroids)
        {
            int val=i;
            int flag=0;
            while(!st.empty() && val<0){
                int t=st.top();
                if(t<0) break;
                if(t<(-1*val))
                {
                    st.pop();
                }
                else if(t==(-1*val)){
                    st.pop();
                    flag=1;
                    break;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1) continue;
            st.push(i);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};