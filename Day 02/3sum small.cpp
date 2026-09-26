class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
       int count =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<target){
                 // If sum < target, every index from j to k-1 gives a valid triplet
                    count+=k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return count;
    }
};
