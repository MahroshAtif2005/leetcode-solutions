class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //monotonic stack
        vector<int> stack;
        //creating the answer vector already filled with zeros.
        //vector<int> name(size, initialValue);
        //Im storing indices on the stack not the value
        vector<int> answer(temperatures.size(),0);
      
        for (int i = 0; i<temperatures.size(); i++){
            while(!stack.empty()&& temperatures[i]>temperatures[stack.back()]){
                int prevIndex=stack.back();
                stack.pop_back();
                answer[prevIndex]=i-prevIndex;
            }
              stack.push_back(i); 
        }
        return answer;
    }
};