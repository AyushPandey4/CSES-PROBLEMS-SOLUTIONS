#include <bits/stdc++.h>
using namespace std;

struct Project {
    int start, end, reward;
};

bool compareByEndTime(const Project& a, const Project& b) {
    return a.end < b.end;  }

int findLastNonConflictingProject(const vector<Project>& projects, int index) {
    int left = 0, right = index - 1;
    int start = projects[index].start;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (projects[mid].end < start) {
            if (projects[mid + 1].end < start) {
                left = mid + 1;
            } else {
                return mid;
            }
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  }

int main() {
    int n;
    cin >> n;
    
    vector<Project> projects(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    
        sort(projects.begin(), projects.end(), compareByEndTime);
    
        vector<long long> dp(n);
    dp[0] = projects[0].reward;      
    for (int i = 1; i < n; ++i) {
                long long excludeCurrent = dp[i - 1];
        
                long long includeCurrent = projects[i].reward;
        int lastNonConflicting = findLastNonConflictingProject(projects, i);
        if (lastNonConflicting != -1) {
            includeCurrent += dp[lastNonConflicting];
        }
        
                dp[i] = max(excludeCurrent, includeCurrent);
    }
    
        cout << dp[n - 1] << endl;
    
    return 0;
}
