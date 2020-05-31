class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        priority_queue<pair<double, vector<int>>> dist;
        vector<vector<int>> result(K, vector<int>(2, 0));
        for (const auto &x : points) {
            double d = -sqrt(pow(x[0], 2) + pow(x[1], 2));
            dist.push({d, x});
        }

        for (int i = 0; i < K; i++) {
            auto point = dist.top();
            dist.pop();
            result[i] = point.second;
        }

        return result;
    }
};
