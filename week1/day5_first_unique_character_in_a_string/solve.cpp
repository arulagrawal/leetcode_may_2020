class Solution {
  public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        int c = 0;
        for (char &ch : s) {
            arr[ch - 'a']++;
            c++;
        }
        c = 0;
        for (char &ch : s) {
            if (arr[ch - 'a'] == 1) {
                return c;
            }
            c++;
        }
        return -1;
    }
};
