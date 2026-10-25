class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
      vector<int> people(121,0);
      int requests=0;

      for(int age : ages){
        people[age]++;
      }

      for(int x = 0; x<=120; x++){
          for(int y = 0; y<=120; y++){
            if(y<= 0.5 * x + 7) continue;
            if(y>x) continue;
            if(y>100 && x<100) continue;
            if(x==y){
                requests += people[x] * (people[x]-1);
            }else{
                requests += people[x] * people[y];
            }
          }
      }
      return requests;
    }
};