class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        if (!num)
            return ans;

        int groups = log2(num) + 1;
        int n = 1;

        for (int i = 0; i < groups; i++) {
            int groupsize = pow(2, i);

            for (int j = 0; j < groupsize; j++) {
                ans[n] = 1 + ans[j];
                n++;
                if (n > num)
                    return ans;
            }
        }
        return ans;
    }
};
