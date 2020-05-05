class Solution {
  public:
    int firstUniqChar(string s) {
        unordered_map<char, int> counter;
        int c = 0;
        for (char &ch : s) {
            counter[ch]++;
            c++;
        }
        c = 0;
        for (char &ch : s) {
            if (counter[ch] == 1) {
                return c;
            }
            c++;
        }
        return -1;
    }
};
