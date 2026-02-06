class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int l=0;
        int h = n-1;
        int b=0;
        while(l<=h){
            if((people[l]+people[h])<=limit){
                l++;
                h--;
            }
            else{
                h--;
            }
            b++;
        }return b;
    }
};