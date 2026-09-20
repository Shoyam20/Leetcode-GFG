class Solution {
public:
    int reverseDegree(string s) {
        vector<int> arr(26);
        int cnt=26;
        for(int i =0;i<26;i++)
        {
            arr[i]=cnt;
            cnt--;
        }
        int sum=0;
        int prod;
        for(int i =0;i<s.size();i++)
        {
            prod=(i+1)*arr[s[i]-'a'];
            sum+=prod;
        }
        return sum;
    }
};