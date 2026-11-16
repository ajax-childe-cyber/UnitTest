1. Позитивные тесты (класс `CalculatePositiveTests`)

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---|---|---|---|---|---|
| 1 | Calculate | Сложение | `'+'`, 2, 3 | код 0, результат 5 | Позитивный | `Calculate_Plus_TwoAndThree_ReturnsFive` |
| 2 | Calculate | Вычитание | `'-'`, 10, 4 | код 0, результат 6 | Позитивный | `Calculate_Minus_TenAndFour_ReturnsSix` |
| 3 | Calculate | Умножение | `'*'`, 3, 4 | код 0, результат 12 | Позитивный | `Calculate_Multiply_ThreeAndFour_ReturnsTwelve` |
| 4 | Calculate | Деление | `'/'`, 6, 3 | код 0, результат 2 | Позитивный | `Calculate_Divide_SixAndThree_ReturnsTwo` |
| 5 | Clojenie (double) | Сложение дробных | 1.5, 2.5 | 4.0 | Позитивный | `Clojenie_Double_OnePointFiveAndTwoPointFive_ReturnsFour` |
| 6 | Clojenie (int) | Сложение целых | 2, 3 | 5 | Позитивный | `Clojenie_Int_TwoAndThree_ReturnsFive` |
| 7 | Vichitanie | Вычитание | 7, 2 | 5 | Позитивный | `Vichitanie_SevenAndTwo_ReturnsFive` |
| 8 | Umnojenie | Умножение | 2, 4 | 8 | Позитивный | `Umnojenie_TwoAndFour_ReturnsEight` |
| 9 | Delenie | Деление | 9, 3 | 3 | Позитивный | `Delenie_NineAndThree_ReturnsThree` |

2. Граничные тесты (класс `CalculateBoundaryTests`)

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---|---|---|---|---|---|
| 10 | Calculate | Сложение нулей | `'+'`, 0, 0 | код 0, результат 0 | Граничный | `Calculate_Plus_ZeroAndZero_ReturnsZero` |
| 11 | Calculate | Вычитание равных чисел | `'-'`, 5, 5 | код 0, результат 0 | Граничный | `Calculate_Minus_EqualNumbers_ReturnsZero` |
| 12 | Calculate | Умножение на ноль | `'*'`, 12345, 0 | код 0, результат 0 | Граничный | `Calculate_Multiply_ByZero_ReturnsZero` |
| 13 | Calculate | Деление нуля на число | `'/'`, 0, 5 | код 0, результат 0 | Граничный | `Calculate_Divide_ZeroByNumber_ReturnsZero` |
| 14 | Calculate | Умножение отрицательного числа | `'*'`, -2, 3 | код 0, результат -6 | Граничный | `Calculate_Multiply_NegativeAndPositive_ReturnsNegative` |
| 15 | Calculate | Деление с дробным результатом | `'/'`, 1, 4 | код 0, результат 0.25 | Граничный | `Calculate_Divide_OneByFour_ReturnsQuarter` |
| 16 | Calculate | Сложение дробных (погрешность double) | `'+'`, 0.1, 0.2 | код 0, результат примерно 0.3 (допуск 0.0001) | Граничный | `Calculate_Plus_ZeroPointOneAndZeroPointTwo_ReturnsAboutZeroPointThree` |
| 17 | Calculate | Умножение больших чисел | `'*'`, 1 000 000 000, 1 000 000 000 | код 0, результат 1e18 | Граничный | `Calculate_Multiply_LargeNumbers_ReturnsProduct` |

3. Негативные тесты (класс `CalculateNegativeTests`)

| № | Функция | Сценарий | Входные данные | Ожидаемый результат | Тип | Тест |
|---|---|---|---|---|---|---|
| 18 | Calculate | Деление на ноль | `'/'`, 5, 0 | код 1 | Негативный | `Calculate_Divide_ByZero_ReturnsCodeOne` |
| 19 | Calculate | Деление нуля на ноль | `'/'`, 0, 0 | код 1 | Негативный | `Calculate_Divide_ZeroByZero_ReturnsCodeOne` |
| 20 | Calculate | Неизвестный знак (буква) | `'x'`, 2, 3 | код 2 | Негативный | `Calculate_UnknownOperator_Letter_ReturnsCodeTwo` |
| 21 | Calculate | Неизвестный знак (пробел) | `' '`, 2, 3 | код 2 | Негативный | `Calculate_UnknownOperator_Space_ReturnsCodeTwo` |
| 22 | Calculate | При ошибке результат не меняется | `result = 777`; вызовы `'/'`, 5, 0 и `'?'`, 5, 5 | `result` остаётся 777 | Негативный | `Calculate_Error_DoesNotChangeResult` |
| 23 | Delenie | Прямое деление на ноль (проверка нуля делается в `Calculate`) | 1, 0 | бесконечность (результат больше 1e308) | Негативный | `Delenie_ByZero_ReturnsInfinity` |

4. Покрытие функций

| Функция | Позитивные | Граничные | Негативные |
|---|---|---|---|
| Calculate | 1, 2, 3, 4 | 10-17 | 18-22 |
| Clojenie (double) | 5 | через Calculate: 10, 16 | - |
| Clojenie (int) | 6 | - | - |
| Vichitanie | 7 | через Calculate: 11 | - |
| Umnojenie | 8 | через Calculate: 12, 14, 17 | - |
| Delenie | 9 | через Calculate: 13, 15 | 23 |

5. Ручная проверка консольного приложения

Ввод и вывод (модули `input`, `output`) не покрыты модульными тестами, поэтому проверяются вручную при запуске `Console`.

| № | Оператор | Первое число | Второе число | Ожидаемый вывод |
|---|---|---|---|---|
| М1 | `+` | 2 | 3 | `Ответ: 5` |
| М2 | `-` | 10 | 4 | `Ответ: 6` |
| М3 | `*` | 3 | 4 | `Ответ: 12` |
| М4 | `/` | 6 | 3 | `Ответ: 2` |
| М5 | `/` | 5 | 0 | `Ответ: На ноль делить незя` |
| М6 | `x` | 2 | 3 | `Ответ: Неверный знак` |

6. Результат запуска

Запуск через Test Explorer: **23 теста запущено, 23 пройдено, 0 не пройдено, 0 пропущено.**
