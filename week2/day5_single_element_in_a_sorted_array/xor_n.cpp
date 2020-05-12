class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int r = 0;
        for (int i : nums) {
            r ^= i;
        }
        return r;
    }
};
