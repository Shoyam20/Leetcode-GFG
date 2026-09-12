class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;


        for(int i = (n*2)-1 ; i >=0;i--)
        {
            int ind =i%n;
            while(!st.empty() && nums[ind]>=st.top()) st.pop();

            if(i<n){
                ans[i]=st.empty()?-1:st.top();
            }
            st.push(nums[ind]);
        }
       
        return ans;
    }
};