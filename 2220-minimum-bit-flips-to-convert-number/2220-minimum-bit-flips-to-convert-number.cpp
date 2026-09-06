class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int i=0;
        while(i<=31)
        {
            if((start & (1<<i)) != (goal & (1<<i))) cnt++;
            i++;
        }

        return cnt;
    }
};