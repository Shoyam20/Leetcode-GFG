class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;

        for(int i=0;i<nums.size();i++)
        {
            // if(m[nums[i]]!=0)
            //     m[nums[i]]=m[nums[i]]^nums[i];
            // else m[nums[i]]=nums[i];
            m[nums[i]]++;
        }

        for(auto i : m)
        {
            if(i.second==1)
            {
                v.push_back(i.first);
            }
            
        }
        return v;
    }
};