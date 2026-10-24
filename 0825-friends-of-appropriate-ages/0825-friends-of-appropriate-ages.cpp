class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> freq(121,0);
        for(int age: ages){
            freq[age]++;
        }

        int requests = 0;

        for(int x = 1; x<=120; x++){
            for(int y = 1; y<=120; y++){
                if(y<=0.5 * x + 7) continue;
                if(y>x) continue;
                if(y>100 && y<100) continue;

                if(x==y){
                  requests += freq[x] * (freq[x] - 1);//cz cant send to itself so subtract that one
                }else{
                  requests += freq[x] * freq[y];
                }

            }
        }
    return requests;
    }
};