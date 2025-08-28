class Solution {
public:
int solve(vector<int>& nums , int l , int h){
    if(l>h)return 0;
    if(l == h)return nums[l];

    int i = nums[l] - solve(nums , l+1 , h);
    int j = nums[h] - solve(nums , l , h-1);

    return max(i , j);
}
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums , 0 , nums.size()-1) >=0;
    }
};