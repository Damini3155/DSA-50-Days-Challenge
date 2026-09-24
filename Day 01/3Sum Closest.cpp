class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        int ans= nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target)return target;
                if(sum<target)j++;
                else k--;

                int temp = abs(sum-target);
                if(temp<diff){
                    diff=temp;
                    ans = sum;
                }
            }
        }
        return ans;
    }
};