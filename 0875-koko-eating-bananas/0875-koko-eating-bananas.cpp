class Solution {
public:
bool helper(vector<int>& piles, int h, int m){
    int curr=0;
    for(int i=0;i<piles.size();i++){
        curr = curr+ ceil((piles[i]*1.0)/m);
    }
    return curr<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());

        int ans=-1;
        while(low<high){
            int m = (low+high)/2;
            if(helper(piles , h , m)){
               
                high = m;

            }else low= m+1;
        }return low;
    }
};