class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int,int> m;
        int sum=0;
        int n=arr.size();
        int l=0;
        int r=0;
        vector<int> minlen(n,INT_MAX);
        int result=INT_MAX;
        int bestmin=INT_MAX;
        while(r<n)
        {
            sum+=arr[r];

            while(l<r && sum>target)
            {
                sum-=arr[l];
                l++;
            }

            if(sum==target)
            {
                int len=r-l+1;
                if(l>0 && minlen[l-1]!=INT_MAX)
                {
                    result=min(result,len+minlen[l-1]);
                }

                bestmin=min(bestmin,len);
            }
            minlen[r]=bestmin;
            r++;
        }
        return result==INT_MAX ? -1 : result;

    
       
    }
};