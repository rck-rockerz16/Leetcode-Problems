class RecentCounter {
private:
    queue<int> queue;

public:
    RecentCounter() {}

    int ping(int t) {
        queue.push(t);

        int lower = t - 3000;
        while (!queue.empty() && queue.front() < lower) {
            queue.pop();
        }
        
        return queue.size();
    }
};

/*
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */