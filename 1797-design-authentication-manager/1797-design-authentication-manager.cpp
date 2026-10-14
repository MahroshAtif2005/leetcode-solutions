class AuthenticationManager {
public:

   unordered_map<string,int> map;//store id and expiry time
    int ttl; //declared outside so all functions can access it
    AuthenticationManager(int timeToLive) {
       ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(map.count(tokenId)){
        if(currentTime<map[tokenId]){
            map[tokenId]=currentTime+ttl;
        }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto& entry: map){
            if(entry.second>currentTime){
              count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */