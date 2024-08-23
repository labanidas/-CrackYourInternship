class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int original,
             int color) {

        if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0 ||
            image[sr][sc] != original)
            return;

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, original, color);
        dfs(image, sr - 1, sc, original, color);
        dfs(image, sr, sc + 1, original, color);
        dfs(image, sr, sc - 1, original, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int original = image[sr][sc];

        if (original != color) {
            dfs(image, sr, sc, original, color);
        }

        return image;
    }
};
