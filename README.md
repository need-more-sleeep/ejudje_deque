# ejudje_deque

## Реализация дека
### Две реализации (обе на плюсах)
Реализуйте дек (двустороннюю очередь), используя только массив.
### Формат ввода
На стандартном потоке ввода задаётся последовательность команд. Пустые
строки игнорируются.
Первая строка всегда содержит "set_size N", где N - максимальный размер
дека, целое число.
Каждая последующая строка содержит ровно одну команду: pushf X, pushb X,
popf, popb или print, где X - произвольная строка без пробелов.
### Формат вывода
Команда print выводит содержимое дека одной строкой, значения разделяются
пробелами. Если дек пуст, то выводится "empty".
Команда pushb добавляет элемент в конец дека, а pushf — в начало.
В случае переполнения дека выводится "overflow".
Команда popf извлекает и выводит первый элемент или "underflow", если дек
пуст. Команда popb делает то же самое для последнего элемента.
Память под дек должна быть выделена не более одного раза, при вызове
команды "set_size".
В любой непонятной ситуации результатом работы любой команды будет
"error".
Результат работы программы выводится в стандартный поток вывода.
