# unique

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Вам надо написать свою реализацию стандартного алгоритма `unique`. Заголовок функции должен быть таким:

```cpp
namespace mystd {
template <typename It>
It unique(It first, It last);
}
```

Функция должна переупорядочить элементы последовательности `[first; last)` так, чтобы подряд идущие одинаковые элементы в ней не встречались. Функция возвращает итератор за последний элемент итоговой последовательности.

Протестируйте вашу функцию на контейнере `list`.

## Формат ввода
На входе дана последовательность целых чисел.

## Формат вывода
Выведите числа, оставленные функцией `unique`.

### Пример 1
| **Ввод** | **Вывод** |
| -------- | --------- |
| 1 2 3    | 1 3       |

### Пример 2
| **Ввод**      | **Вывод** |
| ------------- | --------- |
| 1 1 2 3 3 1 1 | 1 2 3 1   |
