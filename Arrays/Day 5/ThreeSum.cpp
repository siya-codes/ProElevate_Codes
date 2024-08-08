<vector<int>> threeSum(vector<int>& arr) {
      /* set<vector<int>>st;
      for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
            
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
       }
       vector<vevector<int>>ans(st.begin(), st.end());
       return ans;*

       //better 
 
   set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> hashset; 
            for (int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
*/
int n =arr.size();
vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}
};
