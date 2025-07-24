class Solution {
public:
bool helper(vector<int>& piles , int h , int mid){

    int c=0;
    for(int i =0;i<piles.size();i++){
        c += ceil((double)piles[i]/mid);
    }

    return c<= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());

        while(low<high){
            int mid = (low+ high)/2;

            if(helper(piles , h , mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
};