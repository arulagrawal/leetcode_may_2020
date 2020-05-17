class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        int n = p.length();
        int m = s.length();
        if (n > m)
            return indices;

        vector<int> pattern(26, 0);
        vector<int> window(26, 0);

        for (int i = 0; i < n; i++) {
            pattern[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        for (int i = n; i < m; i++) {
            if (pattern == window)
                indices.push_back(i - n);

            window[s[i] - 'a']++;

            window[s[i - n] - 'a']--;
        }

        if (pattern == window)
            indices.push_back(m - n);
        return indices;
    }
};
