#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int maxDiff = 0;

        // Calculate absolute differences
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // If all differences are zero
        if (maxDiff == 0) {
            return 0;
        }

        // Count the frequency of each difference
        vector<int> countDiff(maxDiff + 1, 0);

        for (int d : diff) {
            countDiff[d]++;
        }

        long long K = (long long)k1 + k2;

        // Reduce the largest differences first
        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps = min((long long)countDiff[currDiff], K);

            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;
            K -= countOps;
        }

        // Calculate the minimum sum of squared differences
        long long result = 0;

        for (int d = 1; d <= maxDiff; d++) {
            result += 1LL * countDiff[d] * d * d;
        }

        return result;
    }
};