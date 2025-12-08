class Solution {
public:
bool to_check(vector<int>& piles, int h, int m){
    int count = 0;
    for(int i =0;i<piles.size();i++){
        count = count+ ceil((double)piles[i]/m);
    }
    return count <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<high){
            int m = (low+high)/2;

            if(to_check(piles , h , m)){
                high = m;
            }
            else{
                low = m+1;
            }
        }
        return high;
    }
};