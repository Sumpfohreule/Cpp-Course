#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

template <typename T>
class PriorityQueue {
    private:
        std::vector<T> queue;
    public:
        PriorityQueue<T>();
        void Push(T);
        void Push(std::vector<T>);
        T Pop();
        bool Contains(T);
        unsigned Size();
        bool IsEmpty();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {}

template <typename T>
void PriorityQueue<T>::Push(T element) {
    this->queue.push_back(element);
    std::sort(this->queue.begin(), this->queue.end(), std::greater<T>());
}

template <typename T>
void PriorityQueue<T>::Push(std::vector<T> elements) {
    for (typename std::vector<T>::iterator it = elements.begin(); it != elements.end(); it++) {
        this->queue.push_back(*it);
    }
    std::sort(this->queue.begin(), this->queue.end(), std::greater<T>());
}

template <typename T>
T PriorityQueue<T>::Pop() {
    T value = this->queue.back();
    this->queue.pop_back();
    return(value);
}

template <typename T>
bool PriorityQueue<T>::Contains(T element) {
    bool contains_element = false;
    for (typename std::vector<T>::iterator it = this->queue.begin(); it != this->queue.end(); it++) {
        if (*it == element) {
            contains_element = true;
            break;
        }
    }
    return(contains_element);
}

template <typename T>
unsigned PriorityQueue<T>::Size() {
    return(this->queue.size());
}

template <typename T>
bool PriorityQueue<T>::IsEmpty() {
    return(this->Size() == 0);
}


#endif
