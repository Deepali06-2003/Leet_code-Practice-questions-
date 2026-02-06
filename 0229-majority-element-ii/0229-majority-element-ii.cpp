class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int>res;
        
        unordered_map<int , int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(auto ptr: map){
            if( ptr.second > n/3)res.push_back(ptr.first);
        }return res;
    }
};