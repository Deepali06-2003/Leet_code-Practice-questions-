class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       if(arr.size()<3) return false;
int i=1;
int j=0;
while(i<arr.size() && arr[i]>arr[j]){
i++;j++;
}
if(i==1 || i>=arr.size()) return false;

while(i<arr.size() && arr[i]<arr[j]){
i++;j++;
}
return i==arr.size();
}
       
};