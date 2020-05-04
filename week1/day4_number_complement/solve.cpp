class Solution {
public:
  int findComplement(int num) {
    if (num == 0) {
      return 1;
    }

    int digits = log2(num);
    int ones = pow(2, digits + 1) - 1;

    return num ^ ones;
  }
};
