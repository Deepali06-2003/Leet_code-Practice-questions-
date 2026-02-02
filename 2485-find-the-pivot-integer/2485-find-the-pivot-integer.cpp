class Solution {
public:
    int pivotInteger(int n) {
        if(n<=0)return -1;
        if(n==1)return 1;

        vector<int>pre(n,0);
        vector<int>post(n, 0);

        for(int i =1;i<n;i++){
            pre[i]= pre[i-1]+i;
        }
        for(int i =0;i<n;i++){
            cout<<pre[i]<<' ';
        }
        cout<<endl;
        
        for(int i =n-2;i>=0;i--){
            post[i]= post[i+1]+i+2;
        }
        for(int i =0;i<n;i++){
            cout<<post[i]<<' ';
        }

        for(int i=0;i<n;i++){
            if(pre[i]==post[i])return i+1;
        }
        return -1;
    }
};