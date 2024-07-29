class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n = nums.size();
        for (int i =0; i<n; i++){
            int num =nums[i];
            int more_needed= target- num;
            if(mpp.find(more_needed)!=mpp.end()){
                return{mpp[more_needed],i};
            }
            mpp[num]=i;
        }
        return {-1,-1};
    }
};
