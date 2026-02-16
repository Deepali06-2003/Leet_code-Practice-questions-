class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int ans = 0;
        vector<int>freq(26, 0);

        for(char c: tasks) freq[c - 'A']++;

        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }

        while(!pq.empty()){

            vector<int>curr;
            //updating freq
            for(int i=0; i<(n+1) ;i++){
                if(!pq.empty()){
                    int curr_f = pq.top();
                    pq.pop();
                    curr_f--;

                    curr.push_back(curr_f);
                }
            }

            //pushing back the frequency 
            for(int f: curr){
                if(f > 0)pq.push(f);
            }

            //updating the answer
            if(pq.empty()){
                ans = ans+ curr.size();
            }
            else ans = ans+ (n+1);


        }return ans;
    }
};