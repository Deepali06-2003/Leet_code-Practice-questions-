class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0, c=0;
        while(i<flowerbed.size()){
           if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){
              c++;
                i=i+2;
            }
            else {
                i=i+1;
            }
        }
        if(c>=n){
            return true;
        }
        return false;

    }
};