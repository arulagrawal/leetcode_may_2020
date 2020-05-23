class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                             vector<vector<int>> &B) {
        int m = A.size();
        int n = B.size();

        vector<vector<int>> result;
        int i = 0, j = 0;

        while (i < m && j < n) {
            vector<int> inter = {max(A[i][0], B[j][0]), min(A[i][1], B[j][1])};

            if (inter[0] <= inter[1])
                result.push_back(inter);

            if (A[i][1] <= B[j][1])
                i++;
            else
                j++;
        }

        return result;
    }
};
