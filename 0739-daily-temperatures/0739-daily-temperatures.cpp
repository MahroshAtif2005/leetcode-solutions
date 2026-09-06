class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int> stack;
       vector<int> answer(temperatures.size(),0);
       for (int i = 0;i<temperatures.size();i++){
        while(!stack.empty() && temperatures[i]>temperatures[stack.back()]){
            int prevIndex = stack.back();
            stack.pop_back();
            answer[prevIndex]=i-prevIndex;
        }
        stack.push_back(i);
       }
       return answer;
    }
};