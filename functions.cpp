//���� ���� �������� ������� ����� � ������.

#include "Header.h"
using namespace std;

/* � ����������: ������ ������; ������� ������;
                 ��� ������ � ������ ������ ����� ��������� 49-�� ������;
                 ��� ������ � ������ ������ ����� ��������� 50-�� ������;
                 ���� ������ � ������ ����� ����� ��������� 100-� ������;
                 ���� ������ � ������ ����� ����� ��������� 99-�� ������;
                 ������� ����� ����� ��������� 5-��, 12-��, 50-�� � 100-� ������;
                 �������� ���������� "AuxiliaryValue" ��� ����������� ������� �������� �������� DNF.
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

/* � ������� "InputAverages" �������������� ���� ��������� ������� ��� 5-��, 12-��, 50-�� � 100-� ������.
   */

void InputAverages() {
    cout << "������� ������� �� AVG 5: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average5 = 99999;
    else Average5 = atoi(AuxiliaryValue.c_str());

    cout << "������� ������� �� AVG 12: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average12 = 99999;
    else Average12 = atoi(AuxiliaryValue.c_str());

    cout << "������� ������� �� AVG 50: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average50 = 99999;
    else Average50 = atoi(AuxiliaryValue.c_str());

    cout << "������� ������� �� AVG 100: ";
    cin >> AuxiliaryValue;
    if (AuxiliaryValue == "DNF") Average100 = 99999;
    else Average100 = atoi(AuxiliaryValue.c_str());
}

/* � ������� "Input" �������������� ���� ������ � ����� ������������ ���� ��� 5-�� (12-��, 50-��, 100-��) ������,
   ���� ���������� ������ ��������� 4-�� (11-��, 49-��, 99-��).
   */
void Input() {
    while (true) {
        cout << "������� " << NumberSolve << " ������: ";
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

// ���� ������� ��� 4-�� � 5-�� ������.
/* � ������� "sum4" ��������� ����� ��������� 4-�� ������.
   ��� ����� ����� ��� ������������ ���� ����� ������.
   */
float sum4() {
    float sum = 0;
    for (int i = NumberSolve - 4; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "sum5" ��������� ����� ��������� 5-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���� ������.
   */
float sum5() {
    float sum = 0;
    for (int i = NumberSolve - 4; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "maximum4" �������������� ����� ������������ ������ ����� ��������� 4-�� ������.
   ��� �������� ����� ��� ������������ ���� ����� ������.
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
/* � ������� "maximum5" �������������� ����� ������������ ������ ����� ��������� 5-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���� ������.
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
/* � ������� "minimum4" �������������� ����� ����������� ������ ����� ��������� 4-�� ������.
   ��� �������� ����� ��� ������������ ���� ����� ������.
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
/* � ������� "minimum5" �������������� ����� ����������� ������ ����� ��������� 5-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���� ������.
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
/* � ������� "Output5" �������������� ������������ ���� ����� ������.
   */
void Output5() {
    float FinalSolve = 3 * Average5 - sum4() + minimum4() + maximum4();
    if (sum4() - minimum4() < 3 * Average5) cout << "�� � ����� ������ �������� PB �� AVG 5." << endl;
    else if (sum4() - maximum4() >= 3 * Average5) cout << "�� �� �������� PB �� AVG 5." << endl;
    else cout << "����� �������� PB �� AVG 5, ����� ������� ������� " << FinalSolve << " ������." << endl;
}

// ���� ������� ��� 11-�� � 12-�� ������.
/* � ������� "sum11" ��������� ����� ��������� 11-�� ������.
   ��� ����� ����� ��� ������������ ���� ������������ ������.
   */
float sum11() {
    float sum = 0;
    for (int i = NumberSolve - 11; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "sum12" ��������� ����� ��������� 12-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ����������� ������.
   */
float sum12() {
    float sum = 0;
    for (int i = NumberSolve - 11; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "maximum11" �������������� ����� ������������ ������ ����� ��������� 11-�� ������.
   ��� �������� ����� ��� ������������ ���� ������������ ������.
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
/* � ������� "maximum12" �������������� ����� ������������ ������ ����� ��������� 12-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ����������� ������.
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
/* � ������� "minimum11" �������������� ����� ����������� ������ ����� ��������� 11-�� ������.
   ��� �������� ����� ��� ������������ ���� ������������ ������.
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
/* � ������� "minimum12" �������������� ����� ����������� ������ ����� ��������� 12-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ����������� ������.
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
/* � ������� "Output12" �������������� ������������ ���� ������������ ������.
   */
void Output12() {
    float FinalSolve = 10 * Average12 - sum11() + minimum11() + maximum11();
    if (sum11() - minimum11() < 10 * Average12) cout << "�� � ����� ������ �������� PB �� AVG 12." << endl;
    else if (sum11() - maximum11() >= 10 * Average12) cout << "�� �� �������� PB �� AVG 12." << endl;
    else cout << "����� �������� PB �� AVG 12, ����� ������� ������� " << FinalSolve << " ������." << endl;
}

// ���� ������� ��� 49-�� � 50-�� ������.
/* � ������� "sum49" ��������� ����� ��������� 49-�� ������.
   ��� ����� ����� ��� ������������ ���� ����������� ������.
   */
float sum49() {
    float sum = 0;
    for (int i = NumberSolve - 49; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "sum50" ��������� ����� ��������� 50-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���������� ������.
   */
float sum50() {
    float sum = 0;
    for (int i = NumberSolve - 49; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "maximum49" �������������� ����� ��� ������������ ������ ����� ��������� 49-�� ������.
   ��� �������� ����� ��� ������������ ���� ����������� ������.
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
/* � ������� "maximum50" �������������� ����� ��� ������������ ������ ����� ��������� 50-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���������� ������.
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
/* � ������� "minimum49" �������������� ����� ��� ����������� ������ ����� ��������� 49-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���������� ������.
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
/* � ������� "minimum50" �������������� ����� ��� ����������� ������ ����� ��������� 50-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ���������� ������.
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
/* � ������� "Output50" �������������� ������������ ���� ����������� ������.
   */
void Output50() {
    minimum49();
    maximum49();
    float FinalSolve = 44 * Average50 - sum49() + FirstMaximum49 + SecondMaximum49 + ThirdMaximum49 + FirstMinimum49 + SecondMinimum49 + ThirdMinimum49;
    if (sum49() - FirstMaximum49 - SecondMaximum49 - FirstMinimum49 - SecondMinimum49 - ThirdMinimum49 < 44 * Average50) cout << "�� � ����� ������ �������� PB �� AVG 50." << endl;
    else if (sum49() - FirstMaximum49 - SecondMaximum49 - ThirdMaximum49 - FirstMinimum49 - SecondMinimum49 >= 44 * Average50) cout << "�� �� �������� PB �� AVG 50." << endl;
    else cout << "����� �������� PB �� AVG 50, ����� ������� ������� " << FinalSolve << " ������." << endl;
}

// ���� ������� ��� 99-�� � 100-� ������.
/* � ������� "sum99" ��������� ����� ��������� 99-�� ������.
   ��� ����� ����� ��� ������������ ���� ����� ������.
   */
float sum99() {
    float sum = 0;
    for (int i = NumberSolve - 99; i < NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "sum100" ��������� ����� ��������� 100-� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ��� ������.
   */
float sum100() {
    float sum = 0;
    for (int i = NumberSolve - 99; i <= NumberSolve; i++) {
        sum = sum + Solves[i];
    }
    return sum;
}
/* � ������� "maximum99" �������������� ����� ���� ������������ ������ ����� ��������� 99-�� ������.
   ��� �������� ����� ��� ������������ ���� ����� ������.
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
/* � ������� "maximum100" �������������� ����� ���� ������������ ������ ����� ��������� 100-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ��� ������.
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
/* � ������� "minimum99" �������������� ����� ���� ����������� ������ ����� ��������� 99-�� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ��� ������.
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
/* � ������� "minimum100" �������������� ����� ���� ����������� ������ ����� ��������� 100-� ������.
   ��� ����� ����� ��� �������� �������� ������� ��������� ��� ������.
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
/* � ������� "Output100" �������������� ������������ ���� ����� ������.
   */
void Output100() {
    maximum99();
    minimum99();
    float FinalSolve = 90 * Average100 - sum99() + FirstMinimum99 + SecondMinimum99 + ThirdMinimum99 + FourthMinimum99 + FivthMinimum99 + FirstMaximum99 + SecondMaximum99 + ThirdMaximum99 + FourthMaximum99 + FivthMaximum99;
    if (sum99() - FirstMaximum99 - SecondMaximum99 - ThirdMaximum99 - FourthMaximum99 - FirstMinimum99 - SecondMinimum99 - ThirdMinimum99 - FourthMinimum99 - FivthMinimum99 < 90 * Average100) cout << "�� � ����� ������ �������� PB �� AVG 100." << endl;
    else if (sum99() - FirstMaximum99 - SecondMaximum99 - ThirdMaximum99 - FourthMaximum99 - FivthMaximum99 - FirstMinimum99 - SecondMinimum99 - ThirdMinimum99 - FourthMinimum99 >= 90 * Average100) cout << "�� �� �������� PB �� AVG 100." << endl;
    else cout << "����� �������� PB �� AVG 100, ����� ������� ������� " << FinalSolve << " ������." << endl;
}