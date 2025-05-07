class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        vector<int> v;
        unordered_map<int,int> m;
        for(auto x: arr){
            m[x]++;
        }
        for(int i=100;i<=999;i+=2){
            int num=i;
            int a=num%10;
            num=num/10;
            int b=num%10;
            num=num/10;
            int c=num;
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()){
                        v.push_back(i);
                    }
                    m[b]++;
                }
                m[a]++;
            }
            else continue;
        }
        return v;
    }
};