class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
    //okay so lets try to figure out the id, which will be represented by our answer array index and then lets see how many time stamps did that id travel
    //im thinking we can use smth like hash map
    //so we will keep the id, and the time stamps of the id : start and the end one inclusive
    stack<int> st;
    vector<int> answer(n,0);
    int timeStamp;
    int prevTimeStamp;
    for (int i = 0; i<logs.size(); i++){
       int pos = logs[i].find(':');
       string remaining = logs[i].substr(pos+1);
        int pos2 = remaining.find(':');
        timeStamp = stoi(remaining.substr(pos2+1,logs[i].size()-1));
         int id = stoi(logs[i].substr(0, pos));
       if(logs[i][pos+1]=='s'){
       
        if(!st.empty()){
            answer[st.top()]+=timeStamp-prevTimeStamp;
        }
       
        st.push(id);
        prevTimeStamp = timeStamp;
     }else{
        answer[st.top()] += timeStamp-prevTimeStamp+1;
        
        st.pop();
        prevTimeStamp = timeStamp+1;
     }
     }
     
return answer;

    }
};