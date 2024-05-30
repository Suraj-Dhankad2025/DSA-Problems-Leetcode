class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
    vector<int> f;
    int c = 0;

    // Build the frequency array f
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            c++;
        }
        f.push_back(c);
    }

    // Process each query
    for (auto i : queries) {
        int s = 0, e = f.size() - 1;
        int result = -1;

        // Binary search for the first position where f[mid] == i
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (f[mid] == i) {
                result = mid;
                e = mid - 1; // Search in the left half to find the first occurrence
            } else if (f[mid] > i) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // If result is still -1, it means we didn't find the exact match, handle this case.
        ans.push_back(result);
    }

    return ans;
    }
};