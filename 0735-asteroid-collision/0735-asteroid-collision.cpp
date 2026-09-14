class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
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
        return ans;
    }
};