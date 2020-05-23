class Solution {
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                             vector<vector<int>> &B) {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (intersect(A[i], B[j])) {
                vector<int> inter = {max(A[i][0], B[j][0]),
                                     min(A[i][1], B[j][1])};
                result.push_back(inter);
                int t = i;
                if (A[i][1] <= B[j][1])
                    i++;
                if (B[j][1] <= A[t][1])
                    j++;

            } else {
                if (A[i][1] < B[j][0])
                    i++;
                else
                    j++;
            }
        }

        return result;
    }

    bool intersect(vector<int> &A, vector<int> &B) {
        if (A[0] <= B[0] && A[1] >= B[0])
            return true;
        if (B[0] <= A[0] && B[1] >= A[0])
            return true;
        return false;
    }
};
