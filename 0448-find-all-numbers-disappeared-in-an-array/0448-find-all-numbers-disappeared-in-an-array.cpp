class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        while(i<n){
            int curr = nums[i]-1;
            if(nums[curr]!= nums[i]){
                swap(nums[i], nums[curr]);
            }
            else{
                i++;
            }
        }
vector <int> arr;
for(int j =0;j<n ;j++){
            if(nums[j]-1 != j){
                arr.push_back(j+1);
            }
        }
        return arr;
    }
};