// Copyright 2006 Andrey "Feliksas" Ignatov

#ifndef FINDFINALROOM_ROGUE_H_
#define FINDFINALROOM_ROGUE_H_

#pragma once

#include <set>
#include <string>
#include <memory>
#include "./dungeon.h"

Room* FindFinalRoom(Room* FirstRoom) {
    std::set<std::string> keychain;
    std::set<Room*> visitedRooms, roomQueue;
    std::set<Door*> lockedDoors;
    roomQueue.insert(FirstRoom);

    while (!roomQueue.empty()) {
        Room* currentRoom = *roomQueue.begin();
        visitedRooms.insert(currentRoom);
        roomQueue.erase(roomQueue.begin());
        if (currentRoom->IsFinal()) {
            return currentRoom;
        }

        for (size_t index = 0; index < currentRoom->NumKeys(); ++index) {
            keychain.insert(currentRoom->GetKey(index));
        }

        for (size_t index = 0; index < currentRoom->NumDoors(); ++index) {
            Door* currentDoor = currentRoom->GetDoor(index);
            if (currentDoor->IsOpen()) {
                if (visitedRooms.find(currentDoor->GoThrough()) ==
                                      visitedRooms.end()) {
                    roomQueue.insert(currentDoor->GoThrough());
                }
            } else {
                lockedDoors.insert(currentDoor);
            }
        }
        for (Door* lockedDoor : lockedDoors) {
            for (std::string key : keychain) {
                if (lockedDoor->TryOpen(key)) {
                    if (visitedRooms.find(lockedDoor->GoThrough()) ==
                        visitedRooms.end()) {
                        roomQueue.insert(lockedDoor->GoThrough());
                    }
                }
            }
        }
    }
    Room* result = nullptr;
    return result;
}

#endif  // FINDFINALROOM_ROGUE_H_
