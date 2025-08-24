class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>map;
        for (int x : nums) {
        map[x]++;
        }

        for(auto i : map){
            if(i.second == 1)return i.first;
        }

        return 0;
    }
};