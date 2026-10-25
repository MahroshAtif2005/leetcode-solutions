class Solution {
public:
    string toGoatLatin(string sentence) {
        //put aeiou in set
        unordered_set<char> set = {'a','e','i','o','u'};
        string result = "";
        
        string add  = "";
        stringstream ss(sentence);
        string word;
        int i = 0;

             while(ss>>word){
                i++;
                if(set.contains(tolower(word[0]))){
                    for (int j = 0 ; j<i; j++){
                         add += "a";
                    }
                    result += word + "ma" + add + ' ';
                    add = "";
                }else{
                    for (int j = 0 ; j<i; j++){
                         add += "a";
                    }
                    char temp = word[0];
                    word = word.substr(1);
                    result += word + temp + "ma" + add + ' ';
                    add = "";
                }
            }

            if(!result.empty()){
                result.pop_back();
            }

        return result;
    }
};