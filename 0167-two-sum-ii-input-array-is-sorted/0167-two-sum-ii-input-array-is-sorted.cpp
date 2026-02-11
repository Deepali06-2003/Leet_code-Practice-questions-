class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int h = numbers.size()-1;
        vector<int>res(2, -1);

        while(l<h){
            if((numbers[l]+numbers[h])==target){
                res[0]=l+1;
                res[1]=h+1;
                return res;
            }
            else if((numbers[l]+numbers[h])>target)h--;
            else l++;
        }return res;
    }
};