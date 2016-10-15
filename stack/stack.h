#pragma once

#include <vector>

class Stack {
    public:
        void Push(int x);
        bool Pop();

        int Top() const;
        bool Empty() const;
        size_t Size() const;

    private:
        std::vector<int> stack_;
};

void Stack::Push(int x) {
    stack_.push_back(x);
    return;
}

bool Stack::Pop() {
    if (stack_.empty()) {
        return false;
    }
    stack_.pop_back();
    return true;
}

int Stack::Top() const {
    return stack_.back();
}

bool Stack::Empty() const {
    return stack_.empty();
    // return (Size() == 0);
}

size_t Stack::Size() const {
    return stack_.size();
}
