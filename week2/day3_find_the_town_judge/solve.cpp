class Solution {
  public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> arr(N + 1, 0);

        for (auto t : trust) {
            arr[t[0]]--;
            arr[t[1]]++;
        }

        for (int i = 1; i <= N; i++) {
            if (arr[i] == N - 1)
                return i;
        }

        return -1;
    }
};
