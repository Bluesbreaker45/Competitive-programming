#include <iostream>
#include <queue>

using namespace std;

template<class T>
class MedianFinder {
  private:
    priority_queue<T> maxHeap; // whose top is the (smaller) median
    priority_queue<T, vector<T>, greater<T>> minHeap;

  public:
    void push(T e) {
        if (maxHeap.size() == 0) {
            maxHeap.push(e);
        } else if (e < maxHeap.top()) {
            maxHeap.push(e);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.push(e);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

    void pop() {
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    T median() {
        return maxHeap.top();
    }
};

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        int n;
        cin >> n;
        MedianFinder<int> m;
        for (int _ = 0; _ < n; _++) {
            char op;
            int num;
            cin >> op;
            switch (op)
            {
            case 'I': {
                cin >> num;
                m.push(num);
            }
            break;
            case 'Q': {
                cout << m.median() << endl;
            }
            break;
            case 'D': {
                m.pop();
            }
            break;
            }
        }
    }

    return 0;
}