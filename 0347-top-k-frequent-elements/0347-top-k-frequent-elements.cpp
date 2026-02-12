class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int , int>map;
        for(int i: nums)map[i]++;

        vector<vector<int>>freq(n+1);
        for(auto ptr : map){
            freq[ptr.second].push_back(ptr.first);
        }

        vector<int>res;
        for(int i = n;i>=0;i--){
            for(int j :freq[i]){
                res.push_back(j);
                k--;

                if(k==0)return res;
            }
        }


        return res;
    }
};