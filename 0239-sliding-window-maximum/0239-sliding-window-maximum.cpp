class Solution {
public:
    int max_ele(vector<int>& nums,int l ,int h)
    {
        int m=INT_MIN;
        for(int i=l;i<=h;i++)
        {
            m=max(m,nums[i]);
        }
        return m;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sum=INT_MIN;

        int l=0;
        int h=0;

        vector<int> arr;
        deque<int> dq;
        while(h<nums.size()){
            if(!dq.empty() && dq.front() <=h-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<= nums[h]) dq.pop_back();
            dq.push_back(h);
            if(h>=k-1) arr.push_back(nums[dq.front()]);

            h++;

        }
        return arr;
    }
};