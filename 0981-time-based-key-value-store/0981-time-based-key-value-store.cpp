class TimeMap {
    private:
    unordered_map<string , vector<pair< int , string>>> arr;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        arr[key].emplace_back(timestamp , value);
    }
    
    string get(string key, int timestamp) {
        string res = "";
        auto& temp = arr[key];

        int l =0 , r = temp.size()-1;
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(temp[m].first <= timestamp){
                res = temp[m].second;
                l =m+1;
            }
            else{
                r = m-1;
            }
        }
        return res;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */