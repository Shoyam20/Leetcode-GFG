class Solution {
public:
    int xorOperation(int n, int start) {
        int m=0;
        for(int i=0;i<n;i++){
            m^=(start+2*i);
        }
        return m;
    }
};