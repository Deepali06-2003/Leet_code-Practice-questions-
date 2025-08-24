class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;

        for(auto i :nums){
            map[i]++;
        }

        vector<int>res;
        for(auto i : map){
            if(i.second == 1){
                res.push_back(i.first);
            }
        }return res;
    }
};