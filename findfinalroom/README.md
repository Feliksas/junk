# FindFinalRoom

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Вы находитесь в подземелье и хотите найти из него выход. Подземелье состоит из комнат, соединенных дверями. Некоторые двери открыты и в них свободно можно пройти, некоторые двери закрыты на ключ. Ключи от дверей разбросаны по комнатам.

[Тестирующий код](test.cpp)

### Интерфейс подземелья:  

```cpp
#pragma once

#include <cassert>
#include <vector>
#include <string>
#include <memory>

class Room;

class Door {
 public:
    bool IsOpen() const { return open_; }

    // returns true if key opened door
    bool TryOpen(const std::string& key) {    
        if (key_ == key) open_ = true;
        return open_;
    }

    // door must be open
    Room* GoThrough() {
        assert(open_);
        return to_;
    }

    explicit Door(Room* to) : to_(to), open_(true) {}
    Door(Room* to, const std::string& key) : to_(to), open_(false), key_(key) {}
    
    Door(const Door&) = delete;
    Door(Door&&) = delete;
    Door& operator = (const Door&) = delete;
    Door& operator = (Door&&) = delete;
    
 private:
    bool open_;
    std::string key_;
    Room* to_;
};

class Room {
 public:
    bool IsFinal() { return is_final_; }

    size_t NumKeys() { return keys_.size(); }
    std::string GetKey(size_t key_index) { return keys_[key_index]; }

    size_t NumDoors() { return doors_.size(); }
    Door* GetDoor(size_t door_index) { return doors_[door_index].get(); }

    explicit Room(bool is_final) : is_final_(is_final) {}
    void AddDoor(Room* to) {
        doors_.emplace_back(new Door(to));
        to->doors_.emplace_back(new Door(this));
    }

    void AddDoorWithKey(Room* to, const std::string& key) {
        doors_.emplace_back(new Door(to, key));
        to->doors_.emplace_back(new Door(this, key));
    }

    void AddKey(const std::string& key) { keys_.push_back(key); }

    Room(const Room&) = delete;
    Room(Room&&) = delete;
    Room& operator = (const Room&) = delete;
    Room& operator = (Room&&) = delete;
    
 private:
    bool is_final_;

    std::vector<std::unique_ptr<Door>> doors_;
    std::vector<std::string> keys_;
};
```
Вам необходимо написать функцию `FindFinalRoom`, которая находит выход из подземелья или возвращает `nullptr` если выхода нет.

[Картинка про указатели](https://slon.github.io/best-cpp-course-ever/sem3/D-rogue/pointers.jpg)

Пример работы с классами `Door` и `Room`:

```cpp
#include "dungeon.h"

//
//  *--------*  Open  *--------*
//  * Room 1 * =====> * Room 2 *
//  *--------*        *        *
//      ||            * [key]  *
//      \/            *--------*
//  *--------*
//  * Room 3 *
//  *--------*
//
Room* ExampleGoToThirdRoom(Room* room_1) {
    // go to room 2
    Room* room_2 = starting_room->GetDoor(0)->GoThrough();

    // pick up key
    std::string key = next_room->GetKey(0);

    // return to room 1 and open second door
    Door* closed_door = starting_room->GetDoor(1);    
    closed_door->TryOpen(key);

    // go through door to room 3
    Room* room_3 = closed_door->GoThrough();

    return third_room;
}
```

*Примечания*  
Множества посещённых/непосещённых комнат удобно хранить в `std::set<>`.
