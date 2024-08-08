class Solution {

public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<long long, int>freqMap;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            freqMap[nums[i]]++;
        }
        for(auto&entry:freqMap){
            if(entry.second>1){
             result.push_back(entry.first);

            }
        }
        //sort(result.begin(),result.end());
        return result;
    }
};
