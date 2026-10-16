class Solution {
public:
    int compareVersion(string version1, string version2) {
     stringstream ss1(version1);
     stringstream ss2(version2);
     string num1, num2;

     while(true){
        int a = 0;
        int b = 0;

        bool has1 = bool(getline(ss1,num1,'.'));
        bool has2 = bool(getline(ss2,num2,'.'));

        if(!has1 && !has2){//means both ended
           break;
        }
        
        if(has1){
            a = stoi(num1);
        }
        if(has2){
            b = stoi(num2);
        }

        if(a<b){
            return -1;
        }

        if(b<a){
            return 1;
        }
     }
     return 0;
    }
};