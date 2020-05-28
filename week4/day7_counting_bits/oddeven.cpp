class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        
        for (int i = 1; i <= num; i++) {
            ans[i] = i % 2 ? ans[i/2]+1 : ans[i/2];
        }
        return ans;
        
    }
};