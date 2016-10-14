# unique_ptr

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Реализуйте аналог класса `std::unique_ptr`.

[Тестирующий код](test.cpp)

### Интерфейс класса:  

```cpp
#pragma once

class UniquePtr {
public:
    // put all required methods and operators here

    // see http://ru.cppreference.com/w/cpp/memory/unique_ptr
    // and test.cpp
    
private:
    TestClass* ptr_;
};
```
