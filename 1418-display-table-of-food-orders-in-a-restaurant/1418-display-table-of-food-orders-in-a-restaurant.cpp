class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        // to store table number and then a food name with its freq
        unordered_map<string, unordered_map<string, int>> map;

        for (int i = 0; i < orders.size(); i++) {

            string tableNo = orders[i][1];
            string food = orders[i][2];

            map[tableNo][food]++;
        }

        vector<vector<string>> displayTable;
        set<string> foods; //we used set not unordered set so its sorted and unique
        for (auto& entry : map) {
            for (auto& food : entry.second){
              foods.insert(food.first);
            }
        }
        
        vector<string> header = {"Table"};

        for (auto& food : foods){
            header.push_back(food);
        }
        displayTable.push_back(header);

        //now lets construst a row for each table

        vector<int> tables;
        for(auto& entry: map){
            tables.push_back(stoi(entry.first));
        }

        sort(tables.begin(),tables.end());

        //iterate through the sorted tables vector to construct each row

        for (int table : tables){
            vector<string> row;
            row.push_back(to_string(table));
            for (auto& food : foods) {
               int count = map[to_string(table)][food];
               row.push_back(to_string(count));
               }
             displayTable.push_back(row);
        }
        return displayTable;
    }
};