// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        long long middle = 1;

        while (right >= left) {
            middle = (left + right) / 2;
            if (isBadVersion(middle)) {
                if (!isBadVersion(middle - 1)) {
                    return middle;
                }
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return middle;
    }
};
