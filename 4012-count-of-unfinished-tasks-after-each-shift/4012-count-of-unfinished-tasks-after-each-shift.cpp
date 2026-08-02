class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<int> ans(shifts.size());
        vector<long long> prefix(tasks.size());
        prefix[0] = tasks[0];
        for (int i = 1; i < tasks.size(); i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }
        long long totalWork = prefix[tasks.size() - 1];
        long long completedWork = 0;
        for (int i = 0; i < shifts.size(); i++) {
            completedWork += shifts[i];
            if (completedWork >= totalWork) {
                completedWork = 0;
                ans[i] = 0;
            } else {
                auto it =
                    upper_bound(prefix.begin(), prefix.end(), completedWork);
                ans[i] = tasks.size() - (it - prefix.begin());
            }
        }
        return ans;
    }
};