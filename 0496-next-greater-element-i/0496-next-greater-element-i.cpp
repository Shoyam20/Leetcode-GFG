class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans;
        int flag=0;
        for(int i =0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                flag=0;
                if(nums1[i]==nums2[j])
                {
                    for(int k=j+1 ;k<n2;k++)
                    {
                        if(nums2[k]>nums1[i]) 
                        {
                            ans.push_back(nums2[k]);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0) ans.push_back(-1);
                }
            }
        }
        return ans;

    }
};