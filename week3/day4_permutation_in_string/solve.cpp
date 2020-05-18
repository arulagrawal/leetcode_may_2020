class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (m > n)
            return false;

        vector<int> pattern(26, 0);
        vector<int> window(26, 0);
        for (int i = 0; i < m; i++) {
            pattern[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        for (int i = m; i < n; i++) {
            if (pattern == window)
                return true;
            window[s2[i] - 'a']++;
            window[s2[i - m] - 'a']--;
        }

        if (pattern == window)
            return true;

        return false;
    }
};
