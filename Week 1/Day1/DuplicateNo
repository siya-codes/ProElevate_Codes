class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // nums[]={1,2,3,3,4} or nums[]={4,,3,3,2,1}
        //  no sorted 
        // edge cases : 1 element present  also have duplicate of that one , ans=1
        // loop -> array compare-> lesser or larger , i++, when i got same then i  , return nums[i];
        // use unorderd set for storing the value(int nums, int freq ) , then return the 1st part
       // unordered_set<int, int>>map; 
        //for (int i=0; i<n; i++){
           


          // Approach 1:
         int n=nums.size();
        /*  sort(nums.begin(), nums.end());
          for (int i=0; i<n-1;i++){
            if(nums[i]==nums[i+1]){
            return nums[i];
            }

          }
          return -1;  // *
    }
   // TC: O(N LOG n+N)  SC: O(1)
    
};
*/
vector<int> freq(n + 1, 0);  // Initialize a vector with n+1 elements, all set to 0
for(int i=0; i<n; i++){
    if(freq[nums[i]]==0){
        freq[nums[i]]+=1;
    } else{
        return nums[i];
    }
}
return 0;
    }
};
