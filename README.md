# SegmentTree

В первой строке находится число n — размер массива. (1 ≤ n ≤ 105) Во второй строке находится n чисел ai — элементы массива. Далее содержится описание операций, их количество не превышает 2·10^5. В каждой строке находится одна из следующих операций:
* set i j x — установить все a[k], i ≤ k ≤ j в x.
* add i j x — увеличить все a[k], i ≤ k ≤ j на x.
* min i j — вывести значение минимального элемента в массиве на отрезке с i по j, гарантируется, что (1 ≤ i ≤ j ≤ n).

Все числа во входном файле и результаты выполнения всех операций не превышают по модулю 10^18.
