class Solution {
public:
    bool checkPerfectNumber(int n) {
        int sum=0;
        if(n==1) return false;
        for(long long  i=1;i<=sqrt(n);i++)
        {
            
            if(n%i==0) 
            {
                sum+=i;
                if(i>1 &&(n/i)!=i) sum+=(n/i);
            }
        }
        if(sum==n) return true;
        return false;
    }
};