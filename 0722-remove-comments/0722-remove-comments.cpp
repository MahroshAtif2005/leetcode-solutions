class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> answer;
        bool inBlock = false;
        string line = "";

        for (int i = 0; i < source.size(); i++) {

            for (int j = 0; j < source[i].size(); j++) {

                // If inside block and find */
                // End block comment
                if(inBlock && j+1<source[i].size() && source[i][j]=='*' && 
                source[i][j+1]=='/'){
                    inBlock=false;
                    j++;
                }

                // If outside block and find /*
                // Start block comment
               else if(!inBlock && j+1<source[i].size() && source[i][j]=='/' &&
                source[i][j+1]=='*'){
                    inBlock = true;
                    j++;
                }

                // If outside block and find //
                // Ignore rest of line
               else if(!inBlock && j+1<source[i].size() && source[i][j]=='/' &&
                source[i][j+1]=='/'){
                  break;
                }

                // Otherwise, if outside block
                // Add character to line

              else if(!inBlock){
                    line+=source[i][j];
                }
            }

            // Add completed non-empty lines to answer
            if(!inBlock && !line.empty()){
                answer.push_back(line);
                line = "";
            }
        }

        return answer;
    }
};