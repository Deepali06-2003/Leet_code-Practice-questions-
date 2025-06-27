class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n []= new int [2];
        int s = 0;
        for(int i=0; i<nums.length; i++){
            s = target-nums[i];
            for(int j= i+1;j<nums.length;j++){
                if(s== nums[j]){
                    n[0]= i;
                    n[1]= j;
                    return n;
                }

            }
        }
        return n;
    }
}