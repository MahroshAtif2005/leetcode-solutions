class Solution {
public:
    int compareVersion(string version1, string version2) {
        // okay lets first make sure the size of v1 and v2 is equal
        // then use streamstring on both and start comparing there values using
        // stoi
        stringstream ss1(version1);
        stringstream ss2(version2);

        string num1, num2;

        vector<int> v1;
        vector<int> v2;

        while (getline(ss1, num1, '.')) {
            v1.push_back(stoi(num1));
        }

        while (getline(ss2, num2, '.')) {
            v2.push_back(stoi(num2));
        }

        int n = max(v1.size(), v2.size());

            for (int i = 0; i < n; i++) {
            int a = 0;
            int b = 0;
            if (i < v1.size()) {
                a = v1[i];
            }

            if (i < v2.size()) {
                b = v2[i];
            }

            if(a<b){
                return -1;
            }else if(a>b){
                return 1;
            }
        }

        return 0;
    }
};