class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> map;
        
        for (int i = 0; i<cpdomains.size(); i++){
            int pos = cpdomains[i].find(' ');
            int num = stoi(cpdomains[i].substr(0,pos));
           
           string domain = cpdomains[i].substr(pos+1,cpdomains[i].size());
           map[domain]+= num;

           while(domain.find('.') != string::npos){
             int pos1 =  domain.find('.');
             domain = domain.substr(pos1 + 1); 
             map[domain]+=num; 
           }
        }

        vector<string> answer;
        for(auto domain: map){
            string nums = to_string(domain.second);
            answer.push_back(nums+" "+domain.first);     
        }

        return answer; 
    }
};