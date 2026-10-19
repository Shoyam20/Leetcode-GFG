class Solution {
public:
    int first(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int last(vector<int> &nums,int target){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
             if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> arr;
        int n=nums.size();
        sort(begin(nums),end(nums));

        int start=first(nums,target);
        int end=last(nums,target);

        if(start==-1) return arr;

        for(int i=start;i<=end;i++)
        {
            arr.push_back(i);
        }
        return arr;
    }
};

// 1 2 3 4 4 4 5 6 7 
// 0 1 2 3 4 5 6 7 8