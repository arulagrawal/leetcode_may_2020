class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (middle % 2 == 0) {
                if (nums[middle] == nums[middle + 1]) {
                    left = middle + 2;
                } else {
                    right = middle;
                }
            } else {
                if (nums[middle] == nums[middle - 1]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return nums[left];
    }
};
