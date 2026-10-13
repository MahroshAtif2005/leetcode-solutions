class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
     vector<int> answer(n);
     stack<int> st;
     int prevTime = 0;

     for (int i = 0; i <logs.size(); i++){
        int pos = logs[i].find(':');
        int id = stoi(logs[i].substr(0,pos));

        int pos2 = logs[i].rfind(':');
        int time = stoi(logs[i].substr(pos2+1));

        if(logs[i][pos+1]=='s'){
            if(!st.empty()){
             answer[st.top()] += time - prevTime;
            }
        
        prevTime = time;
        st.push(id);
        }
        else{
            if(!st.empty()){
          answer[st.top()] += time - prevTime +1;
          st.pop();
          prevTime = time+1;
            }
        }
     }
     return answer;
    }
};