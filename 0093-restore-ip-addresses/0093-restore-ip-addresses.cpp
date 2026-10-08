class Solution {
public:
    void backtrack(string s,int start, vector<string>& path,vector<string>& answer){
     
      //base case
      if(path.size()==4){
        if(start==s.size()){
         string ip = path[0]+"."+path[1]+"."+path[2]+"."+path[3];
         answer.push_back(ip);
        }
         return;
      }
      //try segments of sie 1,2,3
      for (int len = 1; len<=3; len++){
        if(start+len>s.size()){
            break;
        }
        string address= s.substr(start,len);
       if(address.size()> 1 && address[0]=='0'){
         continue;
       }
       int num = stoi(address);
       if(num > 255){
        continue;
       }
       //choose 
       path.push_back(address);
       //explore
       backtrack(s,start+len,path,answer);
       //undo
       path.pop_back();
      }
    }
    vector<string> restoreIpAddresses(string s) {
       vector<string> path;
       vector<string> answer;
       if(s.size()<4 || s.size()>12){
       return answer;
       }

       backtrack(s,0,path,answer);

       return answer;
    }
};