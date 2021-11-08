//Этот файл содержит функции ввода и вывода.

#include "Header.h"
using namespace std;

/* В объявлении: массив сборок; счетчик сборок;
                 три лучшие и хучшие сборки среди отдельных 49-ти сборок;
                 три лучшие и хучшие сборки среди отдельных 50-ти сборок;
                 пять лучших и хучших сборк среди отдельных 100-а сборок;
                 пять лучших и хучших сборк среди отдельных 99-ти сборок;
                 среднее время среди последних 5-ти, 12-ти, 50-ти и 100-а сборок;
                 строчная переменная "AuxiliaryValue" для возвожности вносить строчное значение DNF.
   */                              
float Solves[999999] = {};
int NumberSolve = 1;
float FirstMaximum49 = 0, SecondMaximum49 = 0, ThirdMaximum49 = 0, FirstMinimum49 = 0, SecondMinimum49 = 0, ThirdMinimum49 = 0;
float FirstMaximum50 = 0, SecondMaximum50 = 0, ThirdMaximum50 = 0, FirstMinimum50 = 0, SecondMinimum50 = 0, ThirdMinimum50 = 0;
float FirstMaximum99 = 0, SecondMaximum99 = 0, ThirdMaximum99 = 0, FourthMaximum99 = 0, FivthMaximum99 = 0;
float FirstMinimum99 = 0, SecondMinimum99 = 0, ThirdMinimum99 = 0, FourthMinimum99 = 0, FivthMinimum99 = 0;
float FirstMaximum100 = 0, SecondMaximum100 = 0, ThirdMaximum100 = 0, FourthMaximum100 = 0, FivthMaximum100 = 0;
float FirstMinimum100 = 0, SecondMinimum100 = 0, ThirdMinimum100 = 0, FourthMinimum100 = 0, FivthMinimum100 = 0;
float Average5 = 0, Average12 = 0, Average50 = 0, Average100 = 0;
string AuxiliaryValue = "0";

/* В функции "InputAverages" осуществляется ввод среднеего времени для 5-ти, 12-ти, 50-ти и 100-а сборок.
   */

void InputAverages() {
    cout << "Введите среднее по AVG 5: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average5 = 99999;
    else Average5 = atoi(AuxiliaryValue.c_str());

    cout << "Введите среднее по AVG 12: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average12 = 99999;
    else Average12 = atoi(AuxiliaryValue.c_str());

    cout << "Введите среднее по AVG 50: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average50 = 99999;
    else Average50 = atoi(AuxiliaryValue.c_str());

    cout << "Введите среднее по AVG 100: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average100 = 99999;
    else Average100 = atoi(AuxiliaryValue.c_str());
}

/* В функции "Input" осуществляется ввод сборок и вывод предсказания веса для 5-ой (12-ой, 50-ой, 100-ой) сборки,
   если количество сборок превышает 4-ёх (11-ти, 49-ти, 99-ти).
   */
void Input() {
    while (true) {
        cout << "Введите " << NumberSolve << " сборку: ";
        cin >> AuxiliaryValue;

        if (AuxiliaryValue == "DNF") Solves[NumberSolve] = 99999;
        else Solves[NumberSolve] = atoi(AuxiliaryValue.c_str());

        if (NumberSolve > 3) {
            Output5();
        }

        if (NumberSolve > 4) {
            if ((sum5() - maximum5() - minimum5()) / 3 < Average5) {
                Average5 = (sum5() - maximum5() - minimum5()) / 3;
            }
        }

        if (NumberSolve > 10) {
            Output12();
        }

        if (NumberSolve > 11) {
            if ((sum12() - maximum12() - minimum12()) / 10 < Average12) {
                Average12 = (sum12() - maximum12() - minimum12()) / 10;
            }
        }

        if (NumberSolve > 48) {
            Output50();
        }

        if (NumberSolve > 49) {
            maximum50();
            minimum50();
            if ((sum50() - FirstMaximum50 - SecondMaximum50 - ThirdMaximum50 - FirstMinimum50 - SecondMinimum50 - ThirdMinimum50) / 44 < Average50) {
                Average50 = (sum50() - FirstMaximum50 - SecondMaximum50 - ThirdMaximum50 - FirstMinimum50 - SecondMinimum50 - ThirdMinimum50) / 44;
            }
    }

        if (NumberSolve > 98) {
            Output100();
        }

        if (NumberSolve > 99) {
            maximum100();
            minimum100();
            if ((sum100() - FirstMaximum100 - SecondMaximum100 - ThirdMaximum100 - FourthMaximum100 - FivthMaximum100 - FirstMinimum100 - SecondMinimum100 - ThirdMinimum100 - FourthMinimum100 - FivthMinimum100) / 90 < Average100) {
                Average100 = (sum100() - FirstMaximum100 - SecondMaximum100 - ThirdMaximum100 - FourthMaximum100 - FivthMinimum100 - FirstMinimum100 - SecondMinimum100 - ThirdMinimum100 - FourthMinimum100 - FivthMinimum100) / 90;
            }
       }
        NumberSolve++;
    }
}

// Блок функций для 4-ёх и 5-ти сборок.
/* В функции "sum4" считается сумма последних 4-ёх сборок.
   Эта сумма нужна для предсказания веса пятой сборки.
   */
float sum4() {
    float sum = 0;
    for (int i = NumberSolve - 4; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "sum5" считается сумма последних 5-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пяти сборок.
   */
float sum5() {
    float sum = 0;
    for (int i = NumberSolve - 4; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "maximum4" осуществляется поиск максимальной сборки среди последних 4-ёх сборок.
   Это значение нужно для предсказания веса пятой сборки.
   */
float maximum4() {
    float maximum = 0;
    for (int i = NumberSolve - 4; i < NumberSolve; i++) {
        if (Solves[i] > maximum) {
            maximum = Solves[i];
        }
    }
    return maximum;
}
/* В функции "maximum5" осуществляется поиск максимальной сборки среди последних 5-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пяти сборок.
   */
float maximum5() {
    float maximum = 0;
    for (int i = NumberSolve - 4; i <= NumberSolve; i++) {
        if (Solves[i] > maximum) {
            maximum = Solves[i];
        }
    }
    return maximum;
}
/* В функции "minimum4" осуществляется поиск минимальной сборки среди последних 4-ёх сборок.
   Это значение нужно для предсказания веса пятой сборки.
   */
float minimum4() {
    float minimum = 11111111111111;
    for (int i = NumberSolve - 4; i < NumberSolve; i++) {
        if (Solves[i] < minimum) {
            minimum = Solves[i];
        }
    }
    return minimum;
}
/* В функции "minimum5" осуществляется поиск минимальной сборки среди последних 5-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пяти сборок.
   */
float minimum5() {
    float minimum = 11111111111111;
    for (int i = NumberSolve - 4; i <= NumberSolve; i++) {
        if (Solves[i] < minimum) {
            minimum = Solves[i];
        }
    }
    return minimum;
}
/* В функции "Output5" осуществляется предсказание веса пятой сборки.
   */
void Output5() {
    float FinalSolve = 3 * Average5 - sum4() + minimum4() + maximum4();
    if (sum4() - minimum4() < 3 * Average5) cout << "Вы в любом случае обновите PB по AVG 5." << endl;
    else if (sum4() - maximum4() >= 3 * Average5) cout << "Вы не обновите PB по AVG 5." << endl;
    else cout << "Чтобы обновить PB по AVG 5, нужно собрать быстрее " << FinalSolve << " секунд." << endl;
}

// Блок функций для 11-ти и 12-ти сборок.
/* В функции "sum11" считается сумма последних 11-ти сборок.
   Эта сумма нужна для предсказания веса двеннадцатой сборки.
   */
float sum11() {
    float sum = 0;
    for (int i = NumberSolve - 11; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "sum12" считается сумма последних 12-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних двеннадцати сборок.
   */
float sum12() {
    float sum = 0;
    for (int i = NumberSolve - 11; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "maximum11" осуществляется поиск максимальной сборки среди последних 11-ти сборок.
   Это значение нужно для предсказания веса двеннадцатой сборки.
   */
float maximum11() {
    float maximum = 0;
    for (int i = NumberSolve - 11; i < NumberSolve; i++) {
        if (Solves[i] > maximum) {
            maximum = Solves[i];
        }
    }
    return maximum;
}
/* В функции "maximum12" осуществляется поиск максимальной сборки среди последних 12-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних двеннадцати сборок.
   */
float maximum12() {
    float maximum = 0;
    for (int i = NumberSolve - 11; i <= NumberSolve; i++) {
        if (Solves[i] > maximum) {
            maximum = Solves[i];
        }
    }
    return maximum;
}
/* В функции "minimum11" осуществляется поиск минимальной сборки среди последних 11-ти сборок.
   Это значение нужно для предсказания веса двеннадцатой сборки.
   */
float minimum11() {
    float minimum = 11111111;
    for (int i = NumberSolve - 11; i < NumberSolve; i++) {
        if (Solves[i] < minimum) {
            minimum = Solves[i];
        }
    }
    return minimum;
}
/* В функции "minimum12" осуществляется поиск минимальной сборки среди последних 12-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних двеннадцати сборок.
   */
float minimum12() {
    float minimum = 11111111;
    for (int i = NumberSolve - 11; i <= NumberSolve; i++) {
        if (Solves[i] < minimum) {
            minimum = Solves[i];
        }
    }
    return minimum;
}
/* В функции "Output12" осуществляется предсказание веса двеннадцатой сборки.
   */
void Output12() {
    float FinalSolve = 10 * Average12 - sum11() + minimum11() + maximum11();
    if (sum11() - minimum11() < 10 * Average12) cout << "Вы в любом случае обновите PB по AVG 12." << endl;
    else if (sum11() - maximum11() >= 10 * Average12) cout << "Вы не обновите PB по AVG 12." << endl;
    else cout << "Чтобы обновить PB по AVG 12, нужно собрать быстрее " << FinalSolve << " секунд." << endl;
}

// Блок функций для 49-ти и 50-ти сборок.
/* В функции "sum49" считается сумма последних 49-ти сборок.
   Эта сумма нужна для предсказания веса пятидесятой сборки.
   */
float sum49() {
    float sum = 0;
    for (int i = NumberSolve - 49; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "sum50" считается сумма последних 50-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пятидесяти сборок.
   */
float sum50() {
    float sum = 0;
    for (int i = NumberSolve - 49; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "maximum49" осуществляется поиск трёх максимальных сборок среди последних 49-ти сборок.
   Эти значения нужны для предсказания веса пятидесятой сборки.
   */
void maximum49() {
    float firstmaximum = 0, secondmaximum = 0, thirdmaximum = 0;
    for (int i = NumberSolve - 49; i < NumberSolve; i++) {
        if (Solves[i] > firstmaximum) {
            thirdmaximum = secondmaximum;
            secondmaximum = firstmaximum;
            firstmaximum = Solves[i];
        }
        else if (Solves[i] > secondmaximum) {
            thirdmaximum = secondmaximum;
            secondmaximum = Solves[i];
        }
        else if (Solves[i] > thirdmaximum) {
            thirdmaximum = Solves[i];
        }
    }
    FirstMaximum49 = firstmaximum;
    SecondMaximum49 = secondmaximum;
    ThirdMaximum49 = thirdmaximum;
}
/* В функции "maximum50" осуществляется поиск трёх максимальных сборок среди последних 50-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пятидесяти сборок.
   */
void maximum50() {
    float firstmaximum = 0, secondmaximum = 0, thirdmaximum = 0;
    for (int i = NumberSolve - 49; i <= NumberSolve; i++) {
        if (Solves[i] > firstmaximum) {
            thirdmaximum = secondmaximum;
            secondmaximum = firstmaximum;
            firstmaximum = Solves[i];
        }
        else if (Solves[i] > secondmaximum) {
            thirdmaximum = secondmaximum;
            secondmaximum = Solves[i];
        }
        else if (Solves[i] > thirdmaximum) {
            thirdmaximum = Solves[i];
        }
    }
    FirstMaximum50 = firstmaximum;
    SecondMaximum50 = secondmaximum;
    ThirdMaximum50 = thirdmaximum;
}
/* В функции "minimum49" осуществляется поиск трёх минимальных сборок среди последних 49-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пятидесяти сборок.
   */
void minimum49() {
    float firstminimum = 111111, secondminimum = 111111, thirdminimum = 111111;
    for (int i = NumberSolve - 49; i < NumberSolve; i++) {
        if (Solves[i] < firstminimum) {
            thirdminimum = secondminimum;
            secondminimum = firstminimum;
            firstminimum = Solves[i];
        }
        else if (Solves[i] < secondminimum) {
            thirdminimum = secondminimum;
            secondminimum = Solves[i];
        }
        else if (Solves[i] < thirdminimum) {
            thirdminimum = Solves[i];
        }
    }
    FirstMinimum49 = firstminimum;
    SecondMinimum49 = secondminimum;
    ThirdMinimum49 = thirdminimum;
}
/* В функции "minimum50" осуществляется поиск трёх минимальных сборок среди последних 50-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних пятидесяти сборок.
   */
void minimum50() {
    float firstminimum = 111111, secondminimum = 111111, thirdminimum = 111111;
    for (int i = NumberSolve - 49; i <= NumberSolve; i++) {
        if (Solves[i] < firstminimum) {
            thirdminimum = secondminimum;
            secondminimum = firstminimum;
            firstminimum = Solves[i];
        }
        else if (Solves[i] < secondminimum) {
            thirdminimum = secondminimum;
            secondminimum = Solves[i];
        }
        else if (Solves[i] < thirdminimum) {
            thirdminimum = Solves[i];
        }
    }
    FirstMinimum50 = firstminimum;
    SecondMinimum50 = secondminimum;
    ThirdMinimum50 = thirdminimum;
}
/* В функции "Output50" осуществляется предсказание веса пятидесятой сборки.
   */
void Output50() {
    minimum49();
    maximum49();
    float FinalSolve = 44 * Average50 - sum49() + FirstMaximum49 + SecondMaximum49 + ThirdMaximum49 + FirstMinimum49 + SecondMinimum49 + ThirdMinimum49;
    if (sum49() - FirstMaximum49 - SecondMaximum49 - FirstMinimum49 - SecondMinimum49 - ThirdMinimum49 < 44 * Average50) cout << "Вы в любом случае обновите PB по AVG 50." << endl;
    else if (sum49() - FirstMaximum49 - SecondMaximum49 - ThirdMaximum49 - FirstMinimum49 - SecondMinimum49 >= 44 * Average50) cout << "Вы не обновите PB по AVG 50." << endl;
    else cout << "Чтобы обновить PB по AVG 50, нужно собрать быстрее " << FinalSolve << " секунд." << endl;
}

// Блок функций для 99-ти и 100-а сборок.
/* В функции "sum99" считается сумма последних 99-ти сборок.
   Эта сумма нужна для предсказания веса сотой сборки.
   */
float sum99() {
    float sum = 0;
    for (int i = NumberSolve - 99; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "sum100" считается сумма последних 100-а сборок.
   Эта сумма нужна для подсчета среднего времени последних ста сборок.
   */
float sum100() {
    float sum = 0;
    for (int i = NumberSolve - 99; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* В функции "maximum99" осуществляется поиск пяти максимальных сборок среди последних 99-ти сборок.
   Эти значения нужны для предсказания веса сотой сборки.
   */
void maximum99() {
    float firstmaximum = 0, secondmaximum = 0, thirdmaximum = 0, fourthmaximum = 0, fivthmaximum = 0;
    for (int i = NumberSolve - 99; i < NumberSolve; i++) {
        if (Solves[i] > firstmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = secondmaximum;
            secondmaximum = firstmaximum;
            firstmaximum = Solves[i];

        }
        else if (Solves[i] > secondmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = secondmaximum;
            secondmaximum = Solves[i];

        }
        else if (Solves[i] > thirdmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = Solves[i];
        }
        else if (Solves[i] > fourthmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = Solves[i];
        }
        else if (Solves[i] > fivthmaximum) {
            fivthmaximum = Solves[i];
        }
    }
    FirstMaximum99 = firstmaximum;
    SecondMaximum99 = secondmaximum;
    ThirdMaximum99 = thirdmaximum;
    FourthMaximum99 = fourthmaximum;
    FivthMaximum99 = fivthmaximum;
}
/* В функции "maximum100" осуществляется поиск пяти максимальных сборок среди последних 100-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних ста сборок.
   */
void maximum100() {
    float firstmaximum = 0, secondmaximum = 0, thirdmaximum = 0, fourthmaximum = 0, fivthmaximum = 0;
    for (int i = NumberSolve - 99; i <= NumberSolve; i++) {
        if (Solves[i] > firstmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = secondmaximum;
            secondmaximum = firstmaximum;
            firstmaximum = Solves[i];

        }
        else if (Solves[i] > secondmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = secondmaximum;
            secondmaximum = Solves[i];

        }
        else if (Solves[i] > thirdmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = thirdmaximum;
            thirdmaximum = Solves[i];
        }
        else if (Solves[i] > fourthmaximum) {
            fivthmaximum = fourthmaximum;
            fourthmaximum = Solves[i];
        }
        else if (Solves[i] > fivthmaximum) {
            fivthmaximum = Solves[i];
        }
    }
    FirstMaximum100 = firstmaximum;
    SecondMaximum100 = secondmaximum;
    ThirdMaximum100 = thirdmaximum;
    FourthMaximum100 = fourthmaximum;
    FivthMaximum100 = fivthmaximum;
}
/* В функции "minimum99" осуществляется поиск пяти минимальных сборок среди последних 99-ти сборок.
   Эта сумма нужна для подсчета среднего времени последних ста сборок.
   */
void minimum99() {
    float firstminimum = 1111111, secondminimum = 1111111, thirdmimum = 1111111, fourthminimum = 1111111, fivthminimum = 1111111;
    for (int i = NumberSolve - 99; i < NumberSolve; i++) {
        if (Solves[i] < firstminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = secondminimum;
            secondminimum = firstminimum;
            firstminimum = Solves[i];
        }
        else if (Solves[i] < secondminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = secondminimum;
            secondminimum = Solves[i];
        }
        else if (Solves[i] < thirdmimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = Solves[i];
        }
        else if (Solves[i] < fourthminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = Solves[i];
        }
        else if (Solves[i] < fivthminimum) {
            fivthminimum = Solves[i];
        }
    }
    FirstMinimum99 = firstminimum;
    SecondMinimum99 = secondminimum;
    ThirdMinimum99 = thirdmimum;
    FourthMinimum99 = fourthminimum;
    FivthMinimum99 = fivthminimum;
}
/* В функции "minimum100" осуществляется поиск пяти минимальных сборок среди последних 100-а сборок.
   Эта сумма нужна для подсчета среднего времени последних ста сборок.
   */
void minimum100() {
    float firstminimum = 1111111, secondminimum = 1111111, thirdmimum = 1111111, fourthminimum = 1111111, fivthminimum = 1111111;
    for (int i = NumberSolve - 99; i <= NumberSolve; i++) {
        if (Solves[i] < firstminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = secondminimum;
            secondminimum = firstminimum;
            firstminimum = Solves[i];
        }
        else if (Solves[i] < secondminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = secondminimum;
            secondminimum = Solves[i];
        }
        else if (Solves[i] < thirdmimum) {
            fivthminimum = fourthminimum;
            fourthminimum = thirdmimum;
            thirdmimum = Solves[i];
        }
        else if (Solves[i] < fourthminimum) {
            fivthminimum = fourthminimum;
            fourthminimum = Solves[i];
        }
        else if (Solves[i] < fivthminimum) {
            fivthminimum = Solves[i];
        }
    }
    FirstMinimum100 = firstminimum;
    SecondMinimum100 = secondminimum;
    ThirdMinimum100 = thirdmimum;
    FourthMinimum100 = fourthminimum;
    FivthMinimum100 = fivthminimum;
}
/* В функции "Output100" осуществляется предсказание веса сотой сборки.
   */
void Output100() {
    maximum99();
    minimum99();
    float FinalSolve = 90 * Average100 - sum99() + FirstMinimum99 + SecondMinimum99 + ThirdMinimum99 + FourthMinimum99 + FivthMinimum99 + FirstMaximum99 + SecondMaximum99 + ThirdMaximum99 + FourthMaximum99 + FivthMaximum99;
    if (sum99() - FirstMaximum99 - SecondMaximum99 - ThirdMaximum99 - FourthMaximum99 - FirstMinimum99 - SecondMinimum99 - ThirdMinimum99 - FourthMinimum99 - FivthMinimum99 < 90 * Average100) cout << "Вы в любом случае обновите PB по AVG 100." << endl;
    else if (sum99() - FirstMaximum99 - SecondMaximum99 - ThirdMaximum99 - FourthMaximum99 - FivthMaximum99 - FirstMinimum99 - SecondMinimum99 - ThirdMinimum99 - FourthMinimum99 >= 90 * Average100) cout << "Вы не обновите PB по AVG 100." << endl;
    else cout << "Чтобы обновить PB по AVG 100, нужно собрать быстрее " << FinalSolve << " секунд." << endl;
}