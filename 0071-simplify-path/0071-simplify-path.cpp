class Solution {
public:
    string simplifyPath(string path) {
     vector<string> st;
     string folder = "";

     path+= '/'; // so the last folder gets processed too
     for(char c : path){
       if(c!='/'){
        folder+=c;
       }else{
        if(folder==".."){
            if(!st.empty()){
            st.pop_back();
            }
        }
        else if(folder!="" && folder!="."){
            st.push_back(folder);
        }
        folder = ""; //start reading the next folder
       } 
     }
     //build final path
     string answer = "";
     for(string folder: st){
        answer += '/' + folder;
     }
     if(answer==""){
        answer+='/';
     }
     return answer;
    }
};