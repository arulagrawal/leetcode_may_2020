class Solution {
  public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int quotient = num / mid;
            int remain = num % mid;

            if (quotient == mid && remain == 0)
                return true;
            if (quotient > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
