class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        long long ans=(1LL*n& 1LL*(n-1));
        if(ans==0)return true;
        else return false;
    }
};