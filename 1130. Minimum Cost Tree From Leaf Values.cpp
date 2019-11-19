/* 
 * Methods 1: greedily divide and conquer
 * Based on the following obeservations:
 *      the number of non-leaf node is depends on the number of leaf node
 *      the larger leaf is more up(more closer to root) , then the answer is smaller.
 * We have a greedy solution:
 * pick the largest element, try to make it most up 
 * split problem by it into two subproblems.
 *
 * How to make a leaf most up?
 *      Place it in the edge of array. It means the leaf can be the child of root, which is most up.
 * Which edge? Left or right? 
 *      More balance the split is, less the depth is.
 *
 * The time complexity is O(N log N), like quick sort.
 */
class Solution {
    int ret = 0;
    // max_leaf
    int recurse(const vector<int>& arr, int begin, int end) {
        if (begin + 1 == end) {
            return arr[begin];
        }
        int max_index = begin;
        int max_value = arr[begin];
        // find the max value and its index in the interval
        // excluding the ending element
        for (int i = begin + 1; i < end; ++i) {
            if (arr[i] >= max_value) {
                max_value = arr[i];
                max_index = i;
            }
        }
        // greedily divide the intervals
        int l, r;
        if (max_index - begin + 2 <= end - max_index) { // 向后分
            l = recurse(arr, begin, max_index + 1);
            r = recurse(arr, max_index + 1, end);
        } else {    // 向前分
            l = recurse(arr, begin, max_index);
            r = recurse(arr, max_index, end);
        }
        ret += l * r;
        return max(l, r);
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        recurse(arr, 0, arr.size());
        return ret;
    }
};

/*
 * Method 2: stack
 * Intuition
 * When we build a node in the tree, we compared the two numbers a and b.
 * In this process,
 * the smaller one is removed and we won't use it anymore,
 * and the bigger one actually stays.

 * The problem can translated as following:
 * Given an array A, choose two neighbors in the array a and b,
 * we can remove the smaller one min(a,b) and the cost is a * b.
 * What is the minimum cost to remove the whole array until only one left?

 * To remove a number a, it needs a cost a * b, where b >= a.
 * So a has to be removed by a bigger number.
 * We want minimize this cost, so we need to minimize b.

 * b has two candidates, the first bigger number on the left,
 * the first bigger number on the right.

 * The cost to remove a is a * min(left, right).
 */
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};