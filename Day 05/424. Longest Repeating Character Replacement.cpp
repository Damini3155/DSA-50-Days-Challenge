class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxi = 0;
        int maxfreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};