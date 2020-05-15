class Solution {
  public:
    int maxSubarraySumCircular(vector<int> &A) {
        int n = (int)A.size();
        int kad = kadane(A, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            A[i] = -A[i];
        }
        int neg_kad = kadane(A, n);
        if (neg_kad + sum == 0) {
          return kad;
        }
        return max(kad, sum + neg_kad);
    }

    int kadane(vector<int> &A, int n) {
        int c = A[0];
        int m = c;
        for (int i = 1; i < n; i++) {
            c = max(A[i], c + A[i]);
            m = max(c, m);
        }
        return m;
    }
};
