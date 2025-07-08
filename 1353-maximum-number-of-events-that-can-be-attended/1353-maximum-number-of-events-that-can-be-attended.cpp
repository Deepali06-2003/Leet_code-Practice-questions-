class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        int count = 0;
        sort(begin(events) , end(events));
                                        //max heap -> lesser<int>
        priority_queue<int , vector<int>, greater<int>> pq; //min heap

        int day= events[0][0];
        int i =0;
        while(i<n or !pq.empty()){
            //if pq is empty -> then go to next iteration 
            if(pq.empty()){
                day = events[i][0];
            }

            // push the end days of the event whose starting days are equal
            while(i<n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            //attend the event:- count one day at a time
            if(!pq.empty())
            {
                pq.pop();
                count++;
            }

            day++;

            //if end day is less than current day then skip
            while(!pq.empty() && pq.top()< day){
                pq.pop();
            }
           

        }
        return count;
    }
};