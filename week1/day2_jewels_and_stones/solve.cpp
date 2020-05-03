class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> s;
    int count = 0;
    for (char &ch : J) {
      s.insert(ch);
    }

    for (char &ch : S) {
      if (s.find(ch) != s.end()) {
        count++;
      }
    }

    return count;
  }
};
