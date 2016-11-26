// Copyright 2006 Andrey "Feliksas" Ignatov

#ifndef READER_READERS_UTIL_H_
#define READER_READERS_UTIL_H_

#pragma once

#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <string>
#include <utility>

#include "./readers.h"

class LimitReader : public Reader {
 public:
    LimitReader(std::unique_ptr<Reader> reader, size_t limit) :
                reader_(std::move(reader)), bytes_left_(limit) {}

    size_t Read(char* buf, size_t len) override {
        size_t ret = 0;
        size_t bytes_to_read = std::min(len, bytes_left_);
        if (!bytes_to_read) { return 0; }
        ret = reader_->Read(buf, bytes_to_read);
        bytes_left_ -= ret;
        return ret;
    }

 private:
    std::unique_ptr<Reader> reader_;
    size_t bytes_left_;
};

class TeeReader : public Reader {
 public:
    explicit TeeReader(std::vector<std::unique_ptr<Reader>> readers) :
              readers_(std::move(readers)) {
        last_stream_ = readers_.begin();
    }

    size_t Read(char* buf, size_t len) override {
        if (readers_.empty()) { return 0; }
        size_t ret = 0;
        for (; last_stream_ != readers_.end(); ++last_stream_) {
            ret = last_stream_->get()->Read(buf, len);
            if (ret) {
                return ret;
            }
        }
        return ret;
    }

 private:
    std::vector<std::unique_ptr<Reader>> readers_;
    std::vector<std::unique_ptr<Reader>>::iterator last_stream_;
};

class HexDecodingReader : public Reader {
 public:
    explicit HexDecodingReader(std::unique_ptr<Reader> reader) :
                      reader_(std::move(reader)) {}

    size_t Read(char* buf, size_t len) override {
        std::string temp_buf;
        temp_buf.resize(len);
        size_t read_bytes = 0;
        read_bytes = reader_->Read(&(temp_buf[0]), len);
        if (!read_bytes) {
            return 0;
        }
        temp_buf.resize(read_bytes);
        if (read_bytes % 2 == 0) {
            size_t j = 0;
            for (size_t i = 0; i < temp_buf.size(); i += 2) {
               std::istringstream in(temp_buf.substr(i, 2));
               unsigned int tmp;
               in >> std::hex >> tmp;
               buf[j] = static_cast<char>(tmp);
               ++j;
            }
            return j;
        }
        return 0;
    }

 private:
    std::unique_ptr<Reader> reader_;
};

#endif  // READER_READERS_UTIL_H_
