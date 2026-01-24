class NumArray {
public:

vector<int>prefix;
   
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);

        for(int i =1;i<nums.size()+1;i++){
           
            prefix[i] = prefix[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left>right)return 0;
        
        return prefix[right+1]- prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */