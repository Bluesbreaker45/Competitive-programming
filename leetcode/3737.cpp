#include <vector>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // shitty solution, brute force is fastest
        int tnum[1003][1003];

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            tnum[i][i+1] = nums[i] == target ? 1 : 0;
            if (nums[i] == target) {
                count++;
            }
        }

        for (int len = 2; len <= nums.size(); len++) {
            for (int i = 0; i + len <= nums.size(); i++) {
                tnum[i][i+len] = tnum[i][i+len-1] + (nums[i+len-1] == target ? 1 : 0);
                if (tnum[i][i+len] * 2 > len) {
                    count++;
                }
            }
        }
        return count;
    }
};