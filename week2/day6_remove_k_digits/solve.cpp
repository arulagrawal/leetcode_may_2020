class Solution {
  public:
    string removeKdigits(string num, int k) {
        string r;

        for (char &ch : num) {
            while (k && r.length() && r.back() > ch) {
                r.pop_back();
                k--;
            }
            if (r.empty() && ch == '0')
                continue;
            r.push_back(ch);
        }

        if (r.length() > k)
            r.resize(r.length() - k);
        else
            return "0";

        return r;
    }
};
