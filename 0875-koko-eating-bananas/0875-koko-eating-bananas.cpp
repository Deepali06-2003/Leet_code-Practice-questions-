class Solution {
public:
bool to_check(vector<int>piles , int h , int m){
    int hr_req = 0;
    for(int i=0;i<piles.size();i++){
         hr_req += ceil((piles[i]*1.0)/m);
           
    }
    
    return hr_req<= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int high = 1000000000;
        int ans= -1;
        while(l<high){
            int m = (l+high)/2;
            if(to_check(piles, h , m)){
               
                high = m;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
};