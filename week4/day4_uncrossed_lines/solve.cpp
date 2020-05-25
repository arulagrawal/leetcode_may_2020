class Solution {
  public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (A[0] == B[0])
            dp[0][0] = 1;

        for (int j = 1; j < n; j++) {
            int b = A[0] == B[j];
            dp[0][j] = max(b, dp[0][j - 1]);
        }

        for (int i = 1; i < m; i++) {
            int b = A[i] == B[0];
            dp[i][0] = max(b, dp[i - 1][0]);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (A[i] == B[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }

        return dp[m - 1][n - 1];
    }
};
