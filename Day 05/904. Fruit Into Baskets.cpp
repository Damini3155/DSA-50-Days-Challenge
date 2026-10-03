class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int l = 0;
      int maxi = INT_MIN;
      unordered_map<int,int> mp;
      
      for(int r=0;r<fruits.size();r++){
         mp[fruits[r]]++;
         if(mp.size()>2){
          while(mp.size()>2){
              mp[fruits[l]]--;
              
              if(mp[fruits[l]]==0){
                  mp.erase(fruits[l]);
              }
              l++;
          }
         }
          
                         maxi = max(maxi, r - l + 1);
      }
      return maxi;
    }
};