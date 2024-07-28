class Solution {
public:
    void sortColors(vector<int>& nums) { //nums[]={2,0,1}
        // sort, swap 
        int n = nums.size();  // n=3
        int low=0 , mid=0 ,high= n-1; // nums[]={2,  0,   1}          
         //                                       |       |
        //                                        low,mid high

          //{ 1 , 0 ,  2}
            //                                 |   
            //                                  high, mid   1<=1 { 0,1,2}
        
        while( mid <=high) // 0<=2
        if (nums[mid]==0){
            swap(nums[low], nums[mid]); //{ 1 , 0 ,  2}  false  2<=1
            //                                 |   
            //                                  high, mid    mid<=1
            low++;
            mid++;

        }
        else if (nums[mid]==1){
            mid++;                     //{ 1 , 0 ,  2}
            //                                 |   
            //                                  high, mid   1<=1 { 0,1,2}

        }
        else if (nums[mid]==2){
            swap(nums[mid], nums[high]); { 0, 1, 2}
            high --;
            //                       nums[]={2,  0,       1}          
         //                                       |       |
        //                                        low,mid high    high--
        }

    }
};
// nums[]={2,0,1}
// TC: O(N) , SC: =(1)
