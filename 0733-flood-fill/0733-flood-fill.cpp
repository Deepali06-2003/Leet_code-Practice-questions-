class Solution {
public:
void dfs(vector<vector<int>>& image, int sr, int sc,int n , int m, int target, int color){
    if(sr<0 || sc<0 || sr==n|| sc==m || image[sr][sc]== color || image[sr][sc] != target)return;

    image[sr][sc] = color;

    dfs(image , sr+1 , sc , n , m , target , color);
    dfs(image , sr , sc+1 , n , m,target , color);
    dfs(image , sr-1 , sc , n , m , target , color);
    dfs(image , sr , sc-1 , n , m,target , color);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int target = image[sr][sc];

        dfs(image , sr , sc ,n , m , target , color);

        return image;
    }
};