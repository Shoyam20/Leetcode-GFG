class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // vector<int> ans;
        // stack<int> st;
        list<int> st;
        for(auto i : asteroids)
        {
            if(i>0) st.push_back(i);
            else{
                while(!st.empty() && st.back()>0 && st.back() < abs(i)){
                    st.pop_back();
                }

                if(!st.empty() && st.back()==abs(i))
                    st.pop_back();
                else if(st.empty() || st.back()<0 ){
                    st.push_back(i);
                }
            }
        }
            
        vector<int> ans(st.begin(),st.end());

        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};