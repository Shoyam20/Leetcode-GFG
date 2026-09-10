class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int x=1;
        int i=0;
        while(x<=n)
        {
            if(i==target.size()) break;
            v.push_back("Push");
            if(target[i]==x)
             i++;
            else
             v.push_back("Pop");
            x++;
        }
        return v;
    }
};