#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::cout << "vector score!\n";
    vector<int> vKor, vEng, vMat;
    vector<float> vstudent_ave;
    vector<int> vstudent_total;
    vector<int> vsum;//kor, eng, mat
    vector<float> vave;//
    //5명의 학생의 성적을 총합, 평균을 구하시오, 과목별, 개인별. 
    //국리스트 10,20,30,40,50 -> 국 합, 평균
    //영리스트 10,20,30,40,50 -> 영 ...
    //수리스트 10,20,30,40,50 -> 합 .. 평균
 //개인 합,평균
    //개인별은 순서대로, 즉 1번 10,10, 2번 20,20 이렇게 계산합니다.
    for (int i = 0; i < 5; i++)
    {
        vKor.push_back((i + 1) * 10);
        vEng.push_back((i + 1) * 10);
        vMat.push_back((i + 1) * 10);
    }

    int isumKor = 0, isumEng = 0, isumMat = 0;
    float faveKor = 0.0f, faveEng = 0.0f, faveMat = 0.0f;
    for (int i = 0; i < vKor.size(); i++)
    {
        isumKor += vKor.at(i);
        isumEng += vEng.at(i);
        isumMat += vMat.at(i);

        vstudent_total.push_back(vKor.at(i) + vEng.at(i)
            + vMat.at(i));
        vstudent_ave.push_back((vKor.at(i) + vEng.at(i)
            + vMat.at(i)) / 3.0f);
    }
    faveKor = isumKor / 3.0f;
    faveEng = isumEng / 3.0f;
    faveMat = isumMat / 3.0f;

}
