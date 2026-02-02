class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>>res;
        //store the unique vector only
        set<vector<int>> uniq;

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                
                //set the values between j and k;
                unordered_set<long long>hashset;

                for(int k =j+1;k<n;k++){

                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long f_ele = target - sum;


                    if(hashset.count(f_ele)){
                        vector<int> curr = {nums[i], nums[j], nums[k], (int)f_ele};
                        sort(curr.begin(), curr.end());
                        uniq.insert(curr);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        for(auto &v : uniq)
            res.push_back(v);
        return res;
    }
};