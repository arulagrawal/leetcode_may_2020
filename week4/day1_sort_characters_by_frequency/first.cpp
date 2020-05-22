class Solution {
  public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> q;
        map<char, int> m;
        string ans = "";

        for (char &ch : s) {
            m[ch]++;
        }

        for (auto const &x : m) {
            q.push(make_pair(x.second, x.first));
        }
        while (!q.empty()) {
            auto const &x = q.top();

            ans += string(x.first, x.second);

            q.pop();
        }
        return ans;
    }
};
