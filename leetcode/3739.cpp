#include <vector>
using namespace std;

#define ll long long
#define LEN 100000
class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 3, 0);
        freq[n] = 1; // Initialize the frequency of prefix sum 0
        ll prefixSum = n;
        ll freqPrefixSum = 0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                prefixSum++;
                freqPrefixSum += freq[prefixSum - 1];
                freq[prefixSum]++;
            } else {
                prefixSum--;
                freqPrefixSum -= freq[prefixSum];
                freq[prefixSum]++;
            }
            ans += freqPrefixSum;
        }
        return ans;
    }
};