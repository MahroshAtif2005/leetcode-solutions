class Solution {
public:
    string simplifyPath(string path) {
     stack<string> st;
     int index;
      
 
      stringstream ss(path);
      string word;
      
      while(getline(ss,word,'/')){

        if (word=="" || word == "."){
            continue;
        }
        
        if(word == ".."){
             if (!st.empty()) {
              st.pop();
               }
            continue;
        }
        st.push(word);
      }

       string answer;
     while(!st.empty()){
        answer = '/' + st.top() + answer;
        st.pop();
     }
     if (answer.empty()){
        answer = '/';
     }
      return answer;
     }  
};