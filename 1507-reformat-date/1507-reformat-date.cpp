class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string,string> months = {
            {"Jan","01"},
            {"Feb","02"},
            {"Mar","03"},
            {"Apr","04"},
            {"May","05"},
            {"Jun","06"},
            {"Jul","07"},
            {"Aug","08"},
            {"Sep","09"},
            {"Oct","10"},
            {"Nov","11"},
            {"Dec","12"}
        };

        stringstream ss(date);
        string dateNo;
        string month;
        string year;
        ss>>dateNo;
        ss>>month;
        ss>>year;

        string finalDate = dateNo.substr(0,dateNo.size()-2);

        if(finalDate.size() == 1){
           finalDate = "0" + finalDate;
           }

        month = months[month];

        string answer = year + "-" + month + "-" + finalDate;
        return answer;
    }
};