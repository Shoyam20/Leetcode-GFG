class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> rightmin(n);
        int leftmax = nums[0];
        rightmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmin[i] = min(rightmin[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            leftmax=max(leftmax,nums[i]);
            if ((leftmax - rightmin[i]) <= k) {
                return i;
            }
        }

        return -1;
    }
};