# RingBuffer

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Реализуйте класс [RingBuffer](https://en.wikipedia.org/wiki/Circular_buffer)

[Тестирующий код](test.cpp)

### Интерфейс класса:  

```cpp
#pragma once

class RingBuffer {
 public:
    explicit RingBuffer(size_t capacity);

    size_t Size() const;
    bool Empty() const;

    bool TryPush(int element);

    bool TryPop(int* element);

 private:
};
```
Тесты **нужно** запускать локально. Чтобы помочь вам в этом, в этой задаче **есть штраф** за неправильные посылки.
 
В тестирующую систему нужно посылать только заголовочный файл.

*Примечания*  
Для того чтобы скомпилировать и запустить своё решение, положите файлы `test.cpp` и `ring_buffer.h` в одну директорию, а затем выполните в ней команду `g++ test.cpp -std=c++11 && ./a.out` (запустить компилятор и, в случае успеха, запустить исполняемый файл).
