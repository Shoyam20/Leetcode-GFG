class Solution {
public:
    int getdigi(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n /=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();

        vector<int> arr(nums);

        auto func =[&](int n1,int n2){
            int n1digi=getdigi(n1);
            int n2digi=getdigi(n2);

            if(n1digi!=n2digi){
                return n1digi<n2digi;
            }

            return n1<n2;
        };

        sort(begin(arr),end(arr),func);

        unordered_map<int,int> m;

        for(int i=0;i<n;i++)
        {
            m[nums[i]]=i;

        }

        int swap=0;
        for(int i=0;i<n;i++)
        {
            int expected=arr[i];
            int curr =nums[i];

            if(expected==curr)continue;

            int idx=m[expected];

            nums[i]=expected;
            nums[idx]=curr;

            m[expected]=i;
            m[curr]=idx;

            swap++;
        }

        return swap;    
    }
};