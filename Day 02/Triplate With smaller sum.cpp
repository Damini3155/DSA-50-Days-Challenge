class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < target) {
                    // All values from j+1 to k
                    // will also make sum < target
                    count += k - j;
                    j++;
                }
                else {
                    // sum >= target
                    // Need a smaller value
                    k--;
                }
            }
        }

        return count;
    }
};