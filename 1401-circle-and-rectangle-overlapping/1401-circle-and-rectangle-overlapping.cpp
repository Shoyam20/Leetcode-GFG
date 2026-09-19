class Solution {
public:
    bool checkOverlap(int r, int p, int q, int x, int y, int a, int b) {
        //     if((p+r) < x)return false;
        //     else if((p-r) > a) return false;
        //     else if((q+r) < y) return false;
        //     else if((q-r) > b) return false;

        //     return true;

        int newX;
        int newY;

        if (p < x)
            newX = x;
        else if (p > a)
            newX = a;
        else
            newX = p;

        if (q < y)
            newY = y;
        else if (q > b)
            newY = b;
        else
            newY = q;

        long long dx;
        long long dy;

        dx = newX - p;
        dy = newY - q;

        long long npoint = pow(dx, 2) + pow(dy, 2);

        long long cpoint = pow(r, 2);

        if (npoint > cpoint)
            return false;
        return true;
    }
};