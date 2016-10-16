// Copyright 2016 Andrey "Feliksas" Ignatov

#ifndef STATICMAP_STATIC_MAP_H_
#define STATICMAP_STATIC_MAP_H_

#pragma once

#include <vector>
#include <string>
#include <algorithm>

class StaticMap {
 public:
    explicit StaticMap(
                       const std::vector<std::pair<std::string,
                       std::string>>& items);

    bool Find(const std::string& key, std::string* value) const;

 private:
    std::vector<std::pair<std::string, std::string>> items_;
};

StaticMap::StaticMap(const std::vector<std::pair<std::string,
                     std::string>>& items) : items_(items) {
    std::sort(items_.begin(), items_.end());
}

bool StaticMap::Find(const std::string& key, std::string* value) const {
    if (items_.empty()) {
        return false;
    }
    size_t left = 0, right = (items_.size()-1);
    while (left <= right) {
        size_t m = ((left + right) >> 1);
        if (items_[m].first < key) {
            left = m+1;
            continue;
        } else if (items_[m].first > key) {
            right = m-1;
            continue;
        } else if (items_[m].first == key) {
            *value = items_[m].second;
            return true;
        }
    }
    value = nullptr;
    return false;
}

#endif  // STATICMAP_STATIC_MAP_H_
