class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //convert the whole list times in minutes
        //sort the array
        //use for loop with min to get the minimum yet
        int hours = 0;
        int minutes = 0;
        vector<int> answer;
        for (int i = 0; i<timePoints.size(); i++){
          hours = stoi(timePoints[i].substr(0,2));
          minutes = hours*60 + stoi(timePoints[i].substr(3,2));
          answer.push_back(minutes);
        }

        sort(answer.begin(),answer.end());

        int minTime = INT_MAX;
        for(int i = 1; i<answer.size(); i++){
          if(answer[i]-answer[i-1]<minTime){
            minTime = answer[i]-answer[i-1];
          }
        }
     // Time is circular, so we also check the gap across midnight.
     // Subtract the last time from 1440 to get the minutes until midnight.
    // Add the first time to get the minutes elapsed after midnight.
    // Compare this gap with our current minimum difference.
        minTime = min(minTime, 1440 - answer.back() + answer.front());
        return minTime;
    }
};