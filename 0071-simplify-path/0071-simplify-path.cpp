class Solution {
public:
    string simplifyPath(string path) {
  stack<string> st;
  stringstream ss(path);

  string file;
  while(getline(ss,file,'/')){
    if (file==".."){
      if (!st.empty()) {
        st.pop();
       }
  }
     else if (file != "" && file != ".") {
       st.push(file);
      }
}
  string answer;
  while (!st.empty()){
   answer = "/" + st.top() + answer;
   st.pop();
  }
    if(answer==""){
     return "/";
    }
  return answer;
    }
};