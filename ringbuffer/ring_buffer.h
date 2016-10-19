// Copyright 2016 Andrew "Feliksas" Ignatov

#ifndef RINGBUFFER_RING_BUFFER_H_
#define RINGBUFFER_RING_BUFFER_H_

#pragma once

#include <vector>

class RingBuffer {
 public:
    explicit RingBuffer(size_t capacity);
    ~RingBuffer() {
        delete buf_;
    }

    size_t Size() const;
    bool Empty() const;

    bool TryPush(int element);
    bool TryPop(int* element);

 private:
    std::vector<int>* buf_;
};

RingBuffer::RingBuffer(size_t capacity)
          : buf_(new std::vector<int>) {
    buf_->reserve(capacity);
}

size_t RingBuffer::Size() const {
    return buf_->size();
}

bool RingBuffer::Empty() const {
    return buf_->empty();
}

bool RingBuffer::TryPush(int element) {
    if (buf_->size() < buf_->capacity()) {
        buf_->push_back(element);
        return true;
    } else {
        return false;
    }
}

bool RingBuffer::TryPop(int* element) {
    if (!buf_->empty()) {
        *element = *buf_->begin();
        buf_->erase(buf_->begin());
        return true;
    } else {
        return false;
    }
}


#endif  // RINGBUFFER_RING_BUFFER_H_
