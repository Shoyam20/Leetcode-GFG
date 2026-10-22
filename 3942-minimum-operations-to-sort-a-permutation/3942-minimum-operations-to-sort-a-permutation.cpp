class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int a_count=0;
        int d_count=0;

        for(int i=1;i<n;i++){
            a_count+=(nums[i]==(nums[i-1]+1)%n);
            d_count+=(nums[i-1]==(nums[i]+1)%n);
        }

        if(a_count==n-1 && nums[0]==0) return 0;

        if(a_count==n-1){
            int left=n-nums[0];
            int right= 1+(nums.back()+1)+1;

            return min(left,right);
        }


        if(d_count==n-1){
            int left=n-nums.back()+1;
            int right=(nums[0]+1)%n+1;

            return min(left,right);
        }

        return -1;
    }
};