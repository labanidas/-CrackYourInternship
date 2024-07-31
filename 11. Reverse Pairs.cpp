class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        int a[n1];
        int b[n2];

        for (int i = 0; i < n1; i++)
            a[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            b[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                arr[k] = a[i];
                i++;
            } else {
                arr[k] = b[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k++] = a[i++];
        }
        while (j < n2) {
            arr[k++] = b[j++];
        }
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
            int right = mid+1;
            int cnt = 0;
            for(int i=low; i<= mid; i++){
                while(right<=high && arr[i] > (long long)2*arr[right]){
                    right++;
                }
                cnt += (right - (mid+1));
            }

            return cnt;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        int cnt = 0;
        if (l >= r)
            return cnt;
        int mid = (l + r) / 2;
        cnt += mergeSort(nums, l, mid);         
        cnt += mergeSort(nums, mid + 1, r); 
        cnt += countPairs(nums, l, mid, r);     
        merge(nums, l, mid, r);                 
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
         return mergeSort(nums, 0, nums.size() - 1);
    }
};
