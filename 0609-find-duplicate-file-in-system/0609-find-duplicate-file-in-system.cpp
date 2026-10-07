class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < paths.size(); i++) {

            // get directory
            int pos3 = paths[i].find(' ');
            string directory = paths[i].substr(0, pos3);

            // everything after directory
            string remaining = paths[i].substr(pos3 + 1);

            while (remaining.find('(') != string::npos) {

                int pos = remaining.find('(');
                int pos2 = remaining.find(')');

                string fileName = remaining.substr(0, pos);

                string content =
                    remaining.substr(pos + 1, pos2 - pos - 1);

                string filePath = directory + "/" + fileName;

                map[content].push_back(filePath);

                // remove the file we just processed
                remaining = remaining.substr(pos2 + 1);

                // remove leading space
                if (!remaining.empty() && remaining[0] == ' ') {
                    remaining = remaining.substr(1);
                }
            }
        }

        vector<vector<string>> answer;

        for (auto path : map) {
            if (path.second.size() > 1) {
                answer.push_back(path.second);
            }
        }

        return answer;
    }
};