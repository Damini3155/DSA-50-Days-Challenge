class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxi = 0;
        vector<int> freq(128, 0);

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;

            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};