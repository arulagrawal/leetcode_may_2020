class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();

        if (!numCourses || !n)
            return true;

        vector<int> preCounter(numCourses, 0);
        for (int i = 0; i < n; i++) {
            preCounter[prerequisites[i][0]]++;
        }

        queue<int> noPre;
        for (int i = 0; i < numCourses; i++) {
            if (preCounter[i] == 0)
                noPre.push(i);
        }

        int solved = noPre.size();

        while (!noPre.empty()) {
            int top = noPre.front();
            noPre.pop();

            for (int i = 0; i < n; i++) {
                if (prerequisites[i][1] == top) {
                    preCounter[prerequisites[i][0]]--;
                    if (preCounter[prerequisites[i][0]] == 0) {
                        solved++;
                        noPre.push(prerequisites[i][0]);
                    }
                }
            }
        }

        return solved == numCourses;
    }
};
