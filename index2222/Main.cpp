#include "common.h"
#include "FileManager.h"

#define _CRT_SECURE_NO_WARNINGS
/*
1. 학생 3명의 3과목 점수를 파일에 기록하세요.
이름   국어, 영어, 수학
홍길동 100, 10, 20
김남길 20, 100, 30
이공학 30, 60, 100
2. 각학생의 총점과 평균을 구하세요.
3. 결과를 읽어 오세요.
writeSchoolScore()
readSchoolScore()
*/



int main()
{
    cout << "file open and write with binary\n";
    char fname[31] = "../data/myfirstbinary.dat";// "../data/Tree_256x256.png";
    //writeSchoolScore(fname);
    //readSchoolScore(fname);
    binary_test(fname);
}