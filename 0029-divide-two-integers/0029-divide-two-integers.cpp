class Solution {
public:
    int divide(int divi, int div) {
        if(divi==div) return 1;

        bool sign=true;//+ve

        if(divi>=0 && div <0) sign=false;
        if(divi<0 && div >=0) sign=false;
        long long  n=abs((long long)divi);
        long long d=abs((long long)div);
        long long ans=0;
        while(n>=d)
        {
            int cnt=0;
            while(n>=(d << (cnt+1)))
            {
                cnt++;
            }
            ans+=(1<<cnt);
            n-=(d << (cnt));
        }

        if(ans==(1<<31) && sign==true) return INT_MAX;
        if(ans== (1<<31) && sign==false) return INT_MIN;
        ans=sign ? ans : (-ans);
        return ans;
    }
};