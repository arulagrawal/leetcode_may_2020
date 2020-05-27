class Solution {
  public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
        map<int, vector<int>> m;

        for (auto const &x : dislikes) {
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }

        vector<int> group(N + 1, -1);

        for (int i = 1; i <= N; i++) {
            if (group[i] == -1 && !paint(group, i, m, 0))
                return false;
        }
        return true;
    }

    bool paint(vector<int> &group, int i, map<int, vector<int>> &m, int color) {
        group[i] = color;
        for (int x : m[i]) {
            if (group[x] == color)
                return false;
            if (group[x] == -1 && !paint(group, x, m, 1 - color))
                return false;
        }
        return true;
    }
};
