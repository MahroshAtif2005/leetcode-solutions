class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
     stable_sort(logs.begin(),logs.end(), [](const string& a, const string& b){

        int posA = a.find(' ');
        int posB = b.find(' ');

        bool digitA = isdigit(a[posA+1]);
        bool digitB = isdigit(b[posB+1]);

        if(digitA && digitB){ ///both are digit logs, stable sort will do its job
          return false; //short be after alpha logs
        }

        if(digitA) return false;
        if(digitB) return true;

        string contentA = a.substr(posA+1);
        string contentB = b.substr(posB+1);

        if(contentA!=contentB){
            return contentA<contentB;
        }else{
            return a.substr(0,posA)<b.substr(0,posB);
        }

     });
     return logs;
    }
};