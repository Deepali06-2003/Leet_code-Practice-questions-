class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        int c=0 ;

        unordered_map<int, int>map;

        for(int i : nums){
            c = c + map[i];
            map[i]++;
        }
        return c;
    }
};