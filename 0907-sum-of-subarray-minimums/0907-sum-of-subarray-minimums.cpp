class Solution {
public:
    int m=1e9+7;
    vector<int> findNSE(vector<int>& arr)
    {
        stack<int> st;
        int n=arr.size();
        vector<int> NSE(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()] >=arr[i]) st.pop();
            NSE[i]=st.empty() ? n: st.top();

            st.push(i);

        }
        return NSE;
    }
    vector<int> findPSE(vector<int>& arr)
    {
        stack<int> st;
        int n=arr.size();
        vector<int> PSE(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()] >arr[i]) st.pop();

            PSE[i]=st.empty() ? -1: st.top();

            st.push(i);

        }
        return PSE;
    }
    int sumSubarrayMins(vector<int>& arr) {
       vector<int> NSE=findNSE(arr);
       vector<int> PSE=findPSE(arr);

        int total=0;
        int n=arr.size();
       for(int i =0 ;i< n;i++)
       {
        int l=i-PSE[i];
        int r=NSE[i]-i;

        total=(total+(r*l*1LL*arr[i])%m)%m;
       }
       return total;
    }
};