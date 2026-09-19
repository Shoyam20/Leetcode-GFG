class Solution {
public:
    int func(vector<int>& arr) {
        stack<int> st;
        int maxans = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxans = max(maxans, arr[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            maxans = max(maxans, arr[element] * (nse - pse - 1));
        }
        return maxans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area=INT_MIN;
        vector<int> height(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }

            int maxarea=func(height);
            area=max(area,maxarea);
        }
        return area;
    }
};