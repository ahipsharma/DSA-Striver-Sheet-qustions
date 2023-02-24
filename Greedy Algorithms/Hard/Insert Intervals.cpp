class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            // Condition 1 - When output vector is empty or the end time of the current event is less than the start time of next event, then we will simply push the element in the output vector:
            if(output.size()==0 || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            // Condition 2 - When the end time of current event is less then the start time of next event, then, update the end time as max(current event end time and next event end time):
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0], end=intervals[0][1];
        vector<vector<int>> merged;
        merged = merge(intervals);
        return merged;
    }
};