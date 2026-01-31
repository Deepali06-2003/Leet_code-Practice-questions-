class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int , int>map;

        for(int i:nums){
            map[i]++;
        }

        vector<int>res;
        for(auto &ptr : map){
            if(ptr.second > n/3) res.push_back(ptr.first);
        }return res;
    }
};