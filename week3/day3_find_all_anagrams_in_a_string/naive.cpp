class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        int n = p.length();
        if (s.empty() || p.empty())
            return indices;
        if (n > s.length())
            return indices;
        if (s == p) {
            indices.push_back(0);
            return indices;
        }
        sort(p.begin(), p.end());

        for (int i = 0; i <= s.length() - n; i++) {
            string sub = s.substr(i, n);
            // cout << sub << endl;
            // cout << i << " " << i+n << endl;
            sort(sub.begin(), sub.end());
            // cout << sub << endl;
            if (sub == p) {
                indices.push_back(i);
            }
        }
        return indices;
    }
};
