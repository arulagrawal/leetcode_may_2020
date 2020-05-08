class Solution {
  public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }

        auto p1 = coordinates[0];
        auto p2 = coordinates[1];
        if (p1[0] == p2[0]) {
            return false;
        }
        auto m = (p2[1] - p1[1]) / (p2[0] - p1[0]);
        auto c = p1[1] - m * p1[0];

        for (int i = 2; i < coordinates.size(); i++) {
            if (coordinates[i][1] != m * coordinates[i][0] + c) {
                return false;
            }
        }

        return true;
    }
};
