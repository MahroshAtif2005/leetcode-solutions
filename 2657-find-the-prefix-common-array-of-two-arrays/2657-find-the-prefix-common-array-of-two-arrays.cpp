class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      //the index of the array represents teh number
     vector<int> freq(A.size()+1,0);
      vector<int> ans;

  int count = 0;
  for(int i = 0; i<A.size();i++){
    freq[A[i]]++;
    if(freq[A[i]]==2){
      count++;
    }
    freq[B[i]]++;
    if(freq[B[i]]==2){
      count++;
    }
    ans.push_back(count);
  }
  return ans;
    }
};