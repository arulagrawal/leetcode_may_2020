class Solution {
  public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) {
            return "0";
        }

        for (int i = 0; i < k; i++) {
            int j;
            for (j = 0; j < num.length() - 1; j++) {
                if (num[j] > num[j + 1])
                    break;
            }
            num.erase(num.begin() + j);
        }

        while (num.length() > 0 && num[0] == '0') {
            num.erase(num.begin());
        }

        if (num.empty())
            return "0";

        return num;
    }
};
