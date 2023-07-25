class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // The peak is on the right side
            left = mid + 1;
        } else {
            // The peak is on the left side or at the current index
            right = mid;
        }
    }

    return left;
    }
};