class Solution {
  public:
    string frequencySort(string s) {
        vector<int> count(256, 0);
        vector<pair<int, int>> map;
        string ans;

        for (char &ch : s) {
            count[ch]++;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i])
                map.push_back({count[i], i});
        }

        sort(map.begin(), map.end(), greater<>());
        for (auto const &x : map)
            ans += string(x.first, x.second);

        return ans;
    }
};
