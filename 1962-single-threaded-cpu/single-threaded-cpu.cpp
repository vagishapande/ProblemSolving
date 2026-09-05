class process{
public:
    int start;
    int duration;
    int end;
    int index;
    process(int start, int duration, int end, int index){
        this->start = start;
        this->duration = duration;
        this->end = end;
        this->index = index;
    }
};

struct compare{
    bool operator()(const process& a, const process& b){
        if(a.start == b.start){
            if(a.duration == b.duration){
                return a.index > b.index;
            }else return a.duration > b.duration;
        }
        return a.start > b.start;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<process, vector<process>, compare> pq1, pq2;
        
        for(int i=0; i<n; i++){
            pq1.push(process(tasks[i][0], tasks[i][1], tasks[i][0]+tasks[i][1], i));
        }
        
        int time = 0;
        vector<int> ans;
        ans.reserve(n);
        const int inf = 0; // Avoids overflow, zeroes out start time for pq2 sorting. I initially used 2e9+7 which caused interger overflow -_-
        
        while(!pq1.empty()){
            auto curr = pq1.top();
            if(curr.start <= time){
                pq2.push(process(inf, curr.duration, inf+curr.duration, curr.index));
                pq1.pop();
            } else {
                if(pq2.empty()){
                    ans.push_back(curr.index);
                    pq1.pop();
                    time = curr.end;
                } else {
                    auto mi = pq2.top(); 
                    pq2.pop();
                    ans.push_back(mi.index);
                    time += mi.duration;
                }
            }
        }
        
        // Drain any remaining available processes
        while(!pq2.empty()){
            ans.push_back(pq2.top().index);
            pq2.pop();
        }
        
        return ans;
    }
};