class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int targetColor = image[sr][sc];
        if (targetColor != newColor)
            dfs(image, sr, sc, newColor, targetColor);
        return image;
    }

    void dfs(vector<vector<int>> &image, int x, int y, int newColor,
             int targetColor) {
        if (image[x][y] != targetColor) {
            return;
        }

        image[x][y] = newColor;

        if (x + 1 < image.size())
            dfs(image, x + 1, y, newColor, targetColor);
        if (x - 1 >= 0)
            dfs(image, x - 1, y, newColor, targetColor);
        if (y + 1 < image[0].size())
            dfs(image, x, y + 1, newColor, targetColor);
        if (y - 1 >= 0)
            dfs(image, x, y - 1, newColor, targetColor);
    }
};
