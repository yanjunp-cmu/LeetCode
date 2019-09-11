/*
 * use two heap to maintain this data structure
 * one heap for the smaller half of the numbers (use ascending order) such that largest among them is the top
 * one heap for the larger half of the numbers (use descending order) such that smallest among them is the top
 *
 * mid belongs to no heap when odd
 * mid belongs to min_heap (larger half of the number)
 *
 * when the set is at even number
 *      compare num with max_heap.top() and min_heap.top()
 *      if num > min_heap.top(), mid = min_heap.top(), min_heap.pop(), min_heap.push(num)
 *      the whole set contains odd number of integers, where min_heap and max_heap is balanced 
 *      mid belongs to no side but is in between both heaps
 *
  * when the set is at odd number
 *      compare num with mid
 *      if num > mid, max_heap.push(mid), min_heap.push(num)
 *      if num < mid, max_heap.push(num), min_heap.push(mid)
 *      becomes even case, where mid = (max_heap.top() + min_heap.top())/2
**/
class MedianFinder {
private:
    bool is_even;
    // smaller half of the numbers
    priority_queue<int, vector<int>> max_heap;
    // larger half of the numbers
    // greater means x > y, decreasing order
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int mid;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        is_even = true;
        max_heap.push(INT_MIN);
        min_heap.push(INT_MAX);
    }
    
    void addNum(int num) {
        if (is_even){
            int min_num = min_heap.top(), max_num = max_heap.top();
            if (num > min_num){
                mid = min_num;
                min_heap.pop();
                min_heap.push(num);
            } else if (num < max_num) {
                mid = max_num;
                max_heap.pop();
                max_heap.push(num);
            } else {
                mid = num;
            }
        } else {
            if (num > mid){
                max_heap.push(mid);
                min_heap.push(num);
            } else {
                max_heap.push(num);
                min_heap.push(mid);
            }
        }
        is_even = !is_even;
    }
    
    double findMedian() {
        if (is_even){
            return ((double) min_heap.top() + (double) max_heap.top())/2.0;
        } else {
            return mid;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */