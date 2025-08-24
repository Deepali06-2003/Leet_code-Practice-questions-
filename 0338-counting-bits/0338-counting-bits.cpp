class Solution {
public:
int no_bits(int i){
    int c=0;
    while(i != 0){
        i = i &(i-1);
        c++;
    }
    return c;
}
    vector<int> countBits(int n) {
        vector<int>res;

        for(int i =0;i<= n ;i++){
            int x = no_bits(i );
            res.push_back(x);
        }

        return res;
    }
};