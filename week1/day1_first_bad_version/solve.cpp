// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle = 1;
        int lowest = 0;

        while (right >= left) {
            middle = left + (right - left) / 2;
            if (isBadVersion(middle)) {
                lowest = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return lowest;
    }
};
