class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        
        unordered_set<int>set;
        for(int i=0;i<n;i++)set.insert(nums[i]);

        int longest =1;
        for(auto i:set){

            if(set.find(i-1) == set.end()){
                int c=1, x=i;

                while(set.find(x+1)!= set.end()){
                    x= x+1;
                    c++;
                }
                longest = max(longest, c);
            }
        }
        return longest;
        


    }
};