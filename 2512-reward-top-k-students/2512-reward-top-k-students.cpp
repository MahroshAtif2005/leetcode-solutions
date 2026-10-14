class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) 
    {

    unordered_set<string> positiveWords;
    unordered_set<string> negativeWords;
    
    for(int i = 0; i<positive_feedback.size(); i++){
      positiveWords.insert(positive_feedback[i]);
    }

    for (int i = 0; i<negative_feedback.size(); i++){
      negativeWords.insert(negative_feedback[i]);
    }
    
    vector<pair<int,int>> answer; //total points and ids
    for(int i =0 ; i< report.size();i++){
      int score = 0;
        stringstream ss(report[i]);
        string word;
        while(getline(ss,word,' ')){
          if(positiveWords.count(word)){
            score+=3;
          }else if(negativeWords.count(word)){
            score-=1;
          }
        }
        answer.push_back({score,student_id[i]});
    }

    sort(answer.begin(),answer.end(),[](auto& a , auto& b){
      if (a.first != b.first) {
        return a.first > b.first;
        }
      return a.second < b.second;
       
    });
 
    //output top k students now
    vector<int> topK(k);
    for (int i = 0;i<k;i++){
      topK[i]=answer[i].second;
    }
   return topK;
    }
};