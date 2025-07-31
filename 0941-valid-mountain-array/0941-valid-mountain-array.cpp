class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        if(arr.size()<3)return false;

        int i =0;
        while( i < arr.size() && ( arr[i] < arr[i+1] ) ){
                i++;
        }
        if(i ==0 || i == arr.size()-1)return false;

        for(int x = i+1 ; x<arr.size() ;x++){
            if(arr[x] >= arr[x-1])return false;
        }

        //cout<<i;
        return true;

    };
};


