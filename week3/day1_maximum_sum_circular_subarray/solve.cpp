class Solution {
  public:
    int maxSubarraySumCircular(vector<int> &A) {
        int max_sub = INT_MIN;
        int min_sub = INT_MAX;
        int sum = 0;
        int max_here = 0;
        int min_here = 0;

        for (int &i : A) {
            sum += i;

            max_here = max(i, max_here + i);
            max_sub = max(max_sub, max_here);

            min_here = min(i, min_here + i);
            min_sub = min(min_sub, min_here);
        }

        if (sum == min_sub)
            return max_sub;
        return max(max_sub, sum - min_sub);
    }
};
