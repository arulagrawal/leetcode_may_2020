class Solution {
    vector<vector<bool>> visited;

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int targetColor = image[sr][sc];
        visited = vector(image.size(), vector<bool>(image[0].size(), false));
        dfs(image, sr, sc, newColor, targetColor);
        return image;
    }

    void dfs(vector<vector<int>> &image, int x, int y, int newColor,
             int targetColor) {
        if (image[x][y] != targetColor) {
            return;
        }

        image[x][y] = newColor;
        visited[x][y] = true;

        if (x + 1 < image.size() && !visited[x + 1][y])
            dfs(image, x + 1, y, newColor, targetColor);
        if (x - 1 >= 0 && !visited[x - 1][y])
            dfs(image, x - 1, y, newColor, targetColor);
        if (y + 1 < image[0].size() && !visited[x][y + 1])
            dfs(image, x, y + 1, newColor, targetColor);
        if (y - 1 >= 0 && !visited[x][y - 1])
            dfs(image, x, y - 1, newColor, targetColor);
    }
};
