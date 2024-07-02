class Solution {
private:
    int timeDifference(string time1, string time2) {
        int time1_in_mins =
            stoi(time1.substr(0, 2)) * 60 + stoi(time1.substr(3, 2));
        int time2_in_mins =
            stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(3, 2));

        int timeDiff = abs(time1_in_mins - time2_in_mins);
        return min(timeDiff, 1440 - timeDiff);
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < timePoints.size(); i++) {
            int timeDiff = timeDifference(timePoints[i-1], timePoints[i]);
            minDiff = min(timeDiff, minDiff);
        }

        int circularDiff = timeDifference(timePoints.front(), timePoints.back());
        minDiff = min(circularDiff, minDiff);

        return minDiff;
    }
};