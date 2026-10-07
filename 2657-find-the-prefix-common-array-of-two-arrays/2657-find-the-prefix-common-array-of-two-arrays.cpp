class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //create two hashmaps each storyf the array value and its index
        // then we compare if we are at index i we check index i in hashmap and all index i-1
        //the number of matches is what we add in our new array
        unordered_set<int> seenA;
        unordered_set<int> seenB;
        
        vector<int> ans;
        int count = 0;
        for (int i = 0; i<A.size();i++){
            if(seenB.count(A[i])){
             count++;
            }
         
            if(seenA.count(B[i])){
             count++;
            }
            if(A[i]==B[i]){
                count++;
            }

            seenA.insert(A[i]);
            seenB.insert(B[i]);
        
            ans.push_back(count);
        }
     return ans; 
    }
};