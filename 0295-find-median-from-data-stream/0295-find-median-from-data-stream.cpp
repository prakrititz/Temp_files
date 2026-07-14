class MedianFinder {
public:
    int total;
    priority_queue<double>l;
    priority_queue<double>r;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(l.empty()){l.push(num);return;}
        if(num>l.top())r.push(num*-1);
        else l.push(num);
        while(r.size()>l.size())
        {
            l.push(r.top()*-1);
            r.pop();
        }
        while(l.size() > r.size() + 1) {
        r.push(l.top() * -1);
        l.pop();
        }
    }
    
    double findMedian() {
        if(l.size()>r.size())return l.top();
        else return (l.top() + r.top()*-1)/2;
    }
};