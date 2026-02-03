class Solution {
public:
void helper(vector<vector<int>>& image, int sr, int sc, int n, int m, int color, int old_cl) {

        if (sr < 0 || sc < 0 || sr >= n || sc >= m) return;
        if (image[sr][sc] != old_cl) return;

        image[sr][sc] = color;

        helper(image, sr + 1, sc, n, m, color, old_cl);
        helper(image, sr - 1, sc, n, m, color, old_cl);
        helper(image, sr, sc + 1, n, m, color, old_cl);
        helper(image, sr, sc - 1, n, m, color, old_cl);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int old_cl = image[sr][sc];
        if (old_cl == color) return image;

        helper(image, sr, sc, n, m, color, old_cl);
        return image;
    }
};