class Solution {
public:

    void backtrack(string s,int start,vector<string>& answer, vector<string>& paths){
        //base case
        if(paths.size()==4){
            if(start==s.size()){
                answer.push_back(paths[0] + '.' + paths[1] + '.' + paths[2]+ '.'+ paths[3]);
            }
            return;
        }

        //try segments of line 1 - 3
        for(int len = 1; len<=3; len++){
          if(start+len>s.size()){
            break;
          }
          
          string address = s.substr(start,len);
          if(address.size()>1 && address[0]=='0'){
            continue;
          }

          int num = stoi(address);
          if(num>255){
            continue;
          }
          //choose
          paths.push_back(address);
          //explore
          backtrack(s,start+len,answer,paths);
          //undo
          paths.pop_back();

        }
    }

    vector<string> restoreIpAddresses(string s) {
     vector<string> answer;
     vector<string> paths;

     backtrack(s,0,answer,paths);

     return answer;
    }
};