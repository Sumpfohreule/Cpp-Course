#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

template <typename T>
class Priority {
    private:
        T value;
        int priority;
    public:
        Priority(T value, int priority) : value(value), priority(priority) {};
        template <typename U>
        friend bool operator<(const Priority<U>&, const Priority<U>&);
        template <typename U>
        friend bool operator>(const Priority<U>&, const Priority<U>&);
        template <typename U>
        friend bool operator==(const Priority<U>&, const Priority<U>&);
        template <typename U>
        friend bool operator!=(const Priority<U>&, const Priority<U>&);

        T GetValue();
        int GetPriority();
        void SetPriority(int);
};

template <typename T>
bool operator<(const Priority<T>& lhs, const Priority<T>& rhs) {
    return lhs.priority < rhs.priority;
}

template <typename T>
bool operator>(const Priority<T>& lhs, const Priority<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator==(const Priority<T>& lhs, const Priority<T>& rhs) {
    return !(lhs < rhs || rhs < lhs);
}

template <typename T>
bool operator!=(const Priority<T>& lhs, const Priority<T>& rhs) {
    return lhs < rhs || rhs < lhs;
}

template <typename T>
T Priority<T>::GetValue() {
    return this->value;
}

template <typename T>
int Priority<T>::GetPriority() {
    return this->priority;
}

template <typename T>
void Priority<T>::SetPriority(int new_priority) {
    this->priority = new_priority;

}

// PriorityQueue Class
template <typename T>
class PriorityQueue {
    private:
        std::vector<Priority<T>> queue;
    public:
        PriorityQueue<T>();
        void Push(T, int);
        void Push(int);
        void Push(std::vector<int>);
        T Pop();
        bool Contains(T);
        unsigned Size();
        bool IsEmpty();
        void SetPriority(T, int);
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {}

template <typename T>
void PriorityQueue<T>::Push(T element, int priority) {
    this->queue.push_back(Priority<T>(element, priority));
    std::sort(this->queue.begin(), this->queue.end(), std::greater<Priority<T>>());
}

template <typename T>
void PriorityQueue<T>::Push(int element) {
    this->queue.push_back(Priority(element, element));
    std::sort(this->queue.begin(), this->queue.end(), std::greater<Priority<int>>());
}

template <typename T>
void PriorityQueue<T>::Push(std::vector<int> elements) {
    for (std::vector<int>::iterator it = elements.begin(); it != elements.end(); it++) {
        this->queue.push_back(Priority(*it, *it));
    }
    std::sort(this->queue.begin(), this->queue.end(), std::greater<Priority<int>>());
}

template <typename T>
T PriorityQueue<T>::Pop() {
    T value = this->queue.back().GetValue();
    this->queue.pop_back();
    return(value);
}

template <typename T>
bool PriorityQueue<T>::Contains(T element) {
    bool contains_element = false;
    for (int i = 0; i < this->queue.size(); i++) {

        if (this->queue[i].GetValue() == element) {
            contains_element = true;
            break;
        }
    }
    return contains_element;
}

template <typename T>
unsigned PriorityQueue<T>::Size() {
    return this->queue.size();
}

template <typename T>
bool PriorityQueue<T>::IsEmpty() {
    return this->Size() == 0;
}

template <typename T>
void PriorityQueue<T>::SetPriority(T element, int new_priority) {
    for (int i = 0; i < this->queue.size(); i++) {
        Priority<T> vec_element = this->queue[i];
        if (vec_element.GetValue() == element) {
            vec_element.SetPriority(new_priority);
            this->queue[i] = vec_element;
        }
    }
    std::sort(this->queue.begin(), this->queue.end(), std::greater<Priority<T>>());
}


#endif
