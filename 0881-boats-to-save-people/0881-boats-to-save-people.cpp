class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int n = people.size();
        int c=0;

        int l =0, h= n-1;
        while(l<=h){
            
            if((people[l]+ people[h])<=limit){
                l++;
                h--;
                c++;
            }
            else{
                h--;
                c++;
            }
        }
        return c;
    }
};