class Solution {
public:
    long long m;
    long long m1;
    void check(vector<int>& nums, vector<int>& cost,int mid)
    {
        m=0;
        m1=0;

        for(int i =0 ;i< nums.size();i++)
        {
            m=m+ 1LL*(abs(nums[i]-mid))*cost[i];
            m1=m1+1LL*(abs(nums[i]-(mid+1)))*cost[i];
        }
        return ;

    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();

        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        // return h;

        while(l<h)
        {
            int mid =l+(h-l)/2;
            check(nums,cost,mid);
            if(m<=m1)
            {
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return m>=m1 ? m1 : m;
        // return m1;
        
    }
};