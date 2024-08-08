class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n =nums.size();
        int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > 2 * (long long)nums[j]) cnt++;
        }
    }
    return cnt;
}
};


//optimal approach 
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Merging the two halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Append remaining elements of the left half, if any
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Append remaining elements of the right half, if any
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countAndMerge(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        merge(arr, low, mid, high);
        return count;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        int count = mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += countAndMerge(arr, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
