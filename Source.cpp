// ??? ??????? ????. 

/* ??? ????????? ????????? ? ???? ????? (Solves[999999]), ?? ??????? ?? ?????? ??????????? 
? ??????? ????? ?? 5, 12, 50 ? 100 (Average5, Average12, Average50, Average100) ??????
? ????????????? ??????? ????????? ?????? ?? ??????? ????? (?? avg5, avg12, avg50 ? avg100) (???????? ?? ?????? ?? ???????? ???????).

   ???????? ???????: ????? ?????????????? ???????? ??????? ????? (?? avg5, avg12, avg50 ? avg100);
                     ????? ???????? ??? ??????? ??? ???????? ?????? ????? ?????? ????????????? ??????? (?????? FinalSolve);
                     ??????? ????? ?? ?????????.

          ??????? ????? ?? 5-?? ?????? ????????? ???: 
     (????? ???? ?????? - ???????????? ?????? (?? ???????) - ??????????? ?????? (?? ???????)) / 3;
          ??????? ????? ?? 12-?? ?????? ????????? ???:
     (????? ???? ?????? - ???????????? ?????? (?? ???????) - ??????????? ?????? (?? ???????)) / 10;
          ??????? ????? ?? 50-?? ?????? ????????? ???:
     (????? ???? ?????? - ??? ???????????? ?????? (?? ???????) - ??? ??????????? ?????? (?? ???????)) / 44;
          ??????? ????? ?? 100-? ?????? ????????? ???:
     (????? ???? ?????? - ???? ???????????? ?????? (?? ???????) - ???? ??????????? ?????? (?? ???????)) / 90.

     ??????? ????????? ????????? ??????? ??? ???????????????? ?????????? ??????? ?? ???????? ???????

          ????? ?????????????? ????????? ?????? ?? ???????? ??????? ?? 5-?? ??????, ?????? ??????????? ???????:
     (????? 4-?? ?????? - ??????????? ?????? (????? 4-??)) < (3 * ??????? ????? ?? 5-?? ??????).
          ????? ?????????????? ????????? ?????? ?? ???????? ??????? ?? 12-?? ??????, ?????? ??????????? ???????:
     (????? 11-?? ?????? - ??????????? ?????? (????? 11-??)) < (10 * ??????? ????? ?? 12-?? ??????).
          ????? ?????????????? ????????? ?????? ?? ???????? ??????? ?? 50-?? ??????, ?????? ??????????? ???????:
     (????? 49-?? ?????? - ??? ???????????? ?????? (????? 49-??) - ??? ??????????? ?????? (????? 49-??)) < (44 * ??????? ????? ?? 50-?? ??????).
          ????? ?????????????? ????????? ?????? ?? ???????? ??????? ?? 100-? ??????, ?????? ??????????? ???????:
     (????? 99-?? ?????? - ?????? ???????????? ?????? (????? 99-??) - ???? ??????????? ?????? (????? 99-??)) < (90 * ??????? ????? ?? 100-? ??????).

     ???? ??????? ??? ???????????????? ?????????? ??????? ?? ???????? ??????? ?? ???????????, 
     ?? ????????? ????????? ??????? ??????, ????? ?????? ?? ???????????.

          ????? ?????? ?? ????????? ?? ???????? ??????? ?? 5-?? ??????, ?????? ??????????? ???????:
     (????? 4-?? ?????? - ???????????? ?????? (????? 4-??)) >= (3 * ??????? ????? ?? 5-?? ??????).
          ????? ?????? ?? ????????? ?? ???????? ??????? ?? 12-?? ??????, ?????? ??????????? ???????:
     (????? 11-?? ?????? - ???????????? ?????? (????? 11-??)) >= (10 * ??????? ????? ?? 12-?? ??????).   
          ????? ?????? ?? ????????? ?? ???????? ??????? ?? 50-?? ??????, ?????? ??????????? ???????:
     (????? 49-?? ?????? - ??? ???????????? ?????? (????? 49-??) - ??? ??????????? ?????? (????? 49-??)) >= (44 * ??????? ????? ?? 50-?? ??????).
          ????? ?????? ?? ????????? ?? ???????? ??????? ?? 100-? ??????, ?????? ??????????? ???????:
     (????? 99-?? ?????? - ???? ???????????? ?????? (????? 99-??) - ?????? ??????????? ?????? (????? 99-??)) >= (90 * ??????? ????? ?? 100-? ??????).
  
     ???? ??????? ??? ??????, ????? ?????? ?? ??????????? ?? ???????????,
     ?? ????????? ??????? ????? (FinalSolve) ??????? ???????? ????? ??????? ???????????,
     ????? ???????? ?????? ?? ???????? ???????.

     FinalSolve ??? 5-?? ?????? = 3 * ??????? ????? ??? 5-?? ?????? - ????? 4-?? ?????? + ???????????? ?????? (????? 4-??) + ??????????? ?????? (????? 4-??).
     FinalSolve ??? 12-?? ?????? = 10 * ??????? ????? ??? 12-?? ?????? - ????? 11-?? ?????? + ???????????? ?????? (????? 11-??) + ??????????? ?????? (????? 11-??).
     FinalSolve ??? 50-?? ?????? = 44 * ??????? ????? ??? 50-?? ?????? - ????? 49-?? ?????? + ??? ??????????? ?????? (????? 49-??) + ??? ??????????? ?????? (????? 49-??).
     FinalSolve ??? 100-? ?????? = 90 * ??????? ????? ??? 100-? ?????? - ????? 99-?? ?????? + ???? ???????????? ?????? (????? 99-??) + ???? ???????????? ?????? (????? 99-??).
*/

#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

   InputAverages(); // ???? ????????? ??????? ??? 5-??, 12-??, 50-?? ? 100-? ??????.

   Input(); // ???? ?????? ? ????? ???????????? ???? ??? 5-?? (12-??, 50-??, 100-??) ??????
}