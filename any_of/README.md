# any_of

**Ограничение времени:** 1 секунда  
**Ограничение памяти:** 64Mb  
**Ввод:** стандартный ввод или `input.txt`  
**Вывод:** стандартный вывод или `output.txt`  

Вам надо написать свою реализацию стандартного алгоритма `any_of`. Заголовок функции должен быть таким:

```cpp
namespace mystd {
template <typename It, typename Pred>
bool any_of(It first, It last, Pred f);
}
```

Функция должна вернуть `true`, если в последовательности `[first; last)` существует элемент, для которого функция f возвращает истину. В противном случае функция должна вернуть `false`.

Протестируйте вашу функцию для предиката "число является простым" на контейнере `list`.

## Формат ввода
На входе дана последовательность целых чисел.

## Формат вывода
Напечатайте слова true или false в зависимости от того, что вернет ваша функция `any_of`.

### Пример 1
| **Ввод** | **Вывод** |
| -------- | --------- |
| 1 2 3    | true      |

### Пример 2
| **Ввод**    | **Вывод** |
| ----------- | --------- |
| 314 15 92 6 | false     |