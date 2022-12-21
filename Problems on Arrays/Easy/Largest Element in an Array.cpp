class Solution{
public:
    int largest(vector<int> &arr, int n){
        priority_queue<int> pq;
        for(auto it : arr){
            pq.push(it);
        }
        return pq.top();
    }
};