class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>map;

        for(int i: nums){
            map[i]++;
        }

        int i=0;
        for(auto ptr: map){
            if(ptr.second == 1){
                nums[i]= ptr.first;
                i++;
            }
            if(ptr.second >=2){
                nums[i] = ptr.first;
                nums[i+1]= ptr.first;
                i= i+2;
            }
        }

        sort(nums.begin(), nums.begin()+i);
        return i;
    }
};