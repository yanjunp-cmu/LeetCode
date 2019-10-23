/*
 * use a vector to keep track time slots
 * iterate through the vector to find the smallest gap
 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> vec(24*60, 0);
        for (const auto& time : timePoints){
            auto mins = convertToMins(time);
            if (vec[mins]) 
                return 0;
            vec[mins]++;
        }
        int i = 0, j = 24*60-1;
        while(!vec[i]) 
            i++;
        while(!vec[j]) 
            j--;
        int day = 24*60;
        int ret = (i-j+day) % day;
        for (int idx = i+1; idx <= j; idx++){
            if (!vec[idx]) 
                continue;
            ret = min(ret, idx - i);
            i = idx;
        }
        return ret;
    }
private:
    int convertToMins(const string& str){
        int hours = 10 * (str[0] - '0') + (str[1] - '0');
        int mins = 10 * (str[3] - '0') + (str[4] - '0');
        return hours*60 + mins;
    }
};

/*
 * check all adjacent two time nodes and get minimum
 */
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, n = timePoints.size(), diff = 0;
        sort(timePoints.begin(), timePoints.end());
        for (int i = 0; i < n; ++i) {
            string t1 = timePoints[i], t2 = timePoints[(i + 1) % n];
            int h1 = (t1[0] - '0') * 10 + t1[1] - '0';
            int m1 = (t1[3] - '0') * 10 + t1[4] - '0';
            int h2 = (t2[0] - '0') * 10 + t2[1] - '0';
            int m2 = (t2[3] - '0') * 10 + t2[4] - '0';
            diff = (h2 - h1) * 60 + (m2 - m1);
            if (i == n - 1) 
                diff += 24 * 60;
            res = min(res, diff);
        }
        return res;
    }
};