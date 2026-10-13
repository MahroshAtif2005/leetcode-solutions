class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
       //if the amount of the string>1000 add it in the invalid list
       //otherwise add the name in the hashmap with the city and the time
       //later in hashmap for the key name check if the transaction is in 60 mins if its the same city or not, if its not then add that in the invalid strings too
        unordered_map<string,vector<int>> map; //name and index
        int n = transactions.size();

        vector<int> times(n);
        vector<string> cities(n);
        vector<bool> invalid(n, false);
        
        for (int i = 0; i<transactions.size(); i++){
           stringstream ss(transactions[i]);
           string line; //ss extracts string so we need to use line for amount n time

           string name;
           int minutes = 0;
           int amount = 0;
           string city;

           getline(ss,name,','); 

           getline(ss,line,','); 
           minutes = stoi(line);

           getline(ss,line,',');
           amount = stoi(line);

           getline(ss,city,',');

            times[i] = minutes;
            cities[i] = city;

           map[name].push_back(i);
           if(amount>1000){
            invalid[i]=true;
           }
        }

        //lets go through the hashmap now

        for(auto& entry : map){
            for (int i = 0; i<entry.second.size(); i++){
                for(int j = i+1 ;j<entry.second.size();j++){

                   int idx1 = entry.second[i];
                   int idx2 = entry.second[j];

                   if(abs(times[idx1]-times[idx2])<=60 &&
                     cities[idx1]!=cities[idx2]){
                        invalid[idx1]=true;
                        invalid[idx2]=true;
                     }
                }
            }
        }

        //collect invalid transactions
        vector<string> answer;
        for (int i = 0; i<n; i++){
            if(invalid[i]){
                answer.push_back(transactions[i]);
            }
        } 
        return answer;
    }
};