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
                add +='a';
                       
                if(set.contains(tolower(word[0]))){       
                    result += word + "ma" + add + ' ';
               
                }else{
                    
                    char temp = word[0];
                    word = word.substr(1);
                    result += word + temp + "ma" + add + ' ';
               
                }
            }

            if(!result.empty()){
                result.pop_back();
            }

        return result;
    }
};