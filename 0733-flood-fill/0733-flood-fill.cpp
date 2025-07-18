class Solution {
public:
void DFS(vector<vector<int>>&image , int i , int j , int n , int m ,int old_c , int new_c){
    if(i<0 || j<0 || i== n || j == m || image[i][j] == new_c || image[i][j] != old_c){
        return;
    }

    image[i][j] = new_c;

    DFS(image , i+1 , j , n , m, old_c , new_c);
    DFS(image , i , j-1 , n , m, old_c , new_c);
    DFS(image , i-1 , j , n , m, old_c , new_c);
    DFS(image , i , j+1 , n , m, old_c , new_c);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        int old_c = image[sr][sc];
        DFS(image , sr , sc , n , m , old_c , color);

        return image;
        
    }
};