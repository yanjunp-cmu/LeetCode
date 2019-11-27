/*
    Iterative search over free rooms
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // sort the intervals by starting time
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        // use a vector to store all ending time of meeting rooms
        vector<int> rooms;
        // indicator to indicate if a room is found
        bool room_found = false;
        // start looping
        for (int i = 0; i < intervals.size(); i++){
            for (int j = 0; j < rooms.size(); j++){
                if (intervals[i][0] >= rooms[j]){
                    rooms[j] = intervals[i][1];
                    room_found = true;
                    break;
                }
            }
            if (room_found == false){
                rooms.push_back(intervals[i][1]);
            }
            room_found = false;
        }
        return rooms.size();
    }
};

/*
 * Priority Queue
 * the pq stores the end time and greedily search for the first available room
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        int cnt = 1;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); ++i){
            if(pq.top() <= intervals[i][0]) pq.pop();
            pq.push(intervals[i][1]);
            cnt = max(cnt, (int)pq.size());
        }
        return cnt;
    }
};