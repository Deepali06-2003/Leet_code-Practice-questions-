class Solution {
public:
bool helper(vector<int>& piles, int h , int m){

    int c=0;

    for(int i =0;i<piles.size();i++){
        c = c+ ceil((double) piles[i]/m);
    }
    return c<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hh = *max_element(piles.begin(), piles.end());

        while(l<hh){
            int m = (l+hh)/2;

            if(helper(piles, h , m)){
                hh = m;
            }
            else{
                l = m+1;
            }
        }
        return hh;
    }

};