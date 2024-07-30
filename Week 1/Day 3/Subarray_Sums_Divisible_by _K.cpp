class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // subarray >k
        vector<int>fr(k,0);
        fr[0]=1;
        int counter=0;
        int ans=0;
        for(int num:nums){
            if(num>=0){
                counter+=num;
            }else{
                counter+=(num%k)+k;
            }
            counter%=k;
            ans+=fr[counter];
            fr[counter]++;
        }
        return ans;
        
    }
};
