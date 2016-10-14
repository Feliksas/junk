# LruCache

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Реализуйте класс `LruCache`. `LruCache` - это ассоциативный контейнер.
Пока размер кеша не превышает максимальный, он работает как обычный `map`:

Метод `Set()` запоминает новое значение, соответствующее ключу.
Метод `Get()` возвращает `false`, если по ключу ничего не положили. Если ключу соответствует какое-то значение, то `Get` возвращает `true` и это значение.  
Если после `Set()` размер кеша превышает `max_size`, то срабатывает алгоритм `LRU` и кеш удаляет из себя ключ, к которому обращались позже всего (в `Get` или `Set`).

[Тестирующий код](test.cpp)

### Интерфейс класса:  

```cpp
#pragma once

#include <string>
#include <list>
#include <unordered_map>

class LruCache {
 public:
    LruCache(size_t max_size) {}

    void Set(const std::string& key, const std::string& value) {
    }

    bool Get(const std::string& key, std::string* value) {
        return false;
    }

 private:
};
```

*Примечания*  
Внутри `LruCache` должен быть реализован как `std::unordered_map` + `std::list`. Операции `Set` и `Get` должны работать за O(1).  
Помните, что итераторы `std::unordered_map` инвалидируются в момент `rehashing`, а итераторы `std::list` - только когда соответствующий элемент удаляется из контейнера.
