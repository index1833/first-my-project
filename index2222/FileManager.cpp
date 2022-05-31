#include "common.h"
#include <random>
#include <vector>
#include <sstream>

#include "FileManager.h"

struct sStudent {
    string name;
    int    kor;
    int    eng;
    int    mat;
    int    itotal;
    int    fave;
};


void read(char* fname)
{
    ifstream readFile;
    readFile.open(fname);
    char temp[256];
    string strtemp;
    int iscore = 0;

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            //readFile.getline(temp, 256);
            //cout << temp << endl;
            getline(readFile, strtemp);
            iscore = atoi(strtemp.c_str());
            cout << "문자: " << strtemp << endl;
            cout << "숫자: " << iscore << endl;
            cout << "----------" << endl;
        }
    }

    readFile.close();
}

void write(char* fname)
{

    //write
    ofstream writeFile;
    writeFile.open(fname); //존재하면 파일 열고, 아니면 파일 생성

    char arr[31] = "Item name, spece, amount\n";
    writeFile.write(arr, 30);

    string str = "mushroom, +10 force, 3ea\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //유저가 파일 쓰기가 완료됨을 알 수 있도록 해준다.
    cout << "flie writing success!" << endl;
}

void writeRandomNum(char* fname)
{

    //write
    ofstream writeFile;
    writeFile.open(fname); //존재하면 파일 열고, 아니면 파일 생성
    //random test
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    int score = distribution(gen);

    string str = std::to_string(score);
    str += "\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //유저가 파일 쓰기가 완료됨을 알 수 있도록 해준다.
    cout << "flie writing success!" << endl;
}

void readRandomGame(char* fname)
{
    ifstream readFile;
    readFile.open(fname);
    char temp[256];
    string strtemp;
    int iscore = 0;

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            //readFile.getline(temp, 256);
            //cout << temp << endl;
            getline(readFile, strtemp);
            iscore = atoi(strtemp.c_str());
            break;
        }
    }
    readFile.close();


    //game 
    cout << "파일로부터 읽은 숫자를 맞춰보세요.(1~100).. 포기는 0을 입력" << endl;
    int iyournum = -1;
    int icount = 0;
    while (true)
    {
        cout << "당신이 선택한 숫자는? ";
        cin >> iyournum;

        if (iyournum == iscore || iyournum == 0) break;
        else if (iyournum > iscore)
        {
            cout << "정답이 " << iyournum << "보다 작습니다." << endl;
        }
        else
        {
            cout << "정답이 " << iyournum << "보다 큽니다." << endl;
        }
        icount++;
    }
    //결과 처리 
    if (iyournum == 0)
    {
        cout << "아쉽지만 포기하셨군요.다음에 다시 도전하세요!" << endl;
    }
    else
    {
        cout << icount << "번 만에 정답을 맞추셨어요. 축하합니다." << endl;
    }
}

void writeSchoolScore(char* fname)
{
    /*
    1. 학생 3명의 3과목 점수를 파일에 기록하세요.
이름   국어, 영어, 수학
홍길동 100, 10, 20
김남길 20, 100, 30
이공학 30, 60, 100
2. 각학생의 총점과 평균을 구하세요.
3. 결과를 읽어 오세요. */
//write
    ofstream writeFile;
    writeFile.open(fname); //존재하면 파일 열고, 아니면 파일 생성

    string str = "이름 국어 영어 수학\n";
    writeFile.write(str.c_str(), str.size());

    str = "홍길동 100 10 20\n";
    writeFile.write(str.c_str(), str.size());

    str = "김남길 20 100 30\n";
    writeFile.write(str.c_str(), str.size());

    str = "이공학 30 60 100\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //유저가 파일 쓰기가 완료됨을 알 수 있도록 해준다.
    cout << "flie writing success!" << endl;
}

void readSchoolScore(char* fname)
{
    ifstream readFile;
    readFile.open(fname);
    char temp[256];
    string strtemp;
    int iscore = 0;
    int kor, eng, mat, itotal, student_num;
    float fave;
    vector<string> vWordList;
    string word;
    sStudent slist[3];

    if (readFile.is_open())
    {

        while (!readFile.eof())
        {
            getline(readFile, strtemp);
            stringstream sstream(strtemp);
            while (getline(sstream, word, ' '))
            {
                vWordList.push_back(word);
            }
        }
    }
    readFile.close();
    //결과 출력 
    student_num = 3;
    int igap = 4;
    int istart = 4;
    for (int i = 0; i < student_num; i++)
    {
        istart = igap * (i + 1);
        slist[i].name = vWordList[istart + 0];//4번째 워드 홍길동
        slist[i].kor = atoi(vWordList[istart + 1].c_str());//5 .. 국어
        slist[i].eng = atoi(vWordList[istart + 2].c_str());//5 .. 영어
        slist[i].mat = atoi(vWordList[istart + 3].c_str());//5 .. 수학
        slist[i].itotal = slist[i].kor + slist[i].eng + slist[i].mat;
        slist[i].fave = slist[i].itotal / (float)student_num;
    }

    for (int i = 0; i < student_num; i++)
    {
        cout << slist[i].name <<
            ", 국어 :" << slist[i].kor <<
            ", 영어 :" << slist[i].eng <<
            ", 수학 :" << slist[i].mat <<
            ", 총점 :" << slist[i].itotal <<
            ", 평균 :" << slist[i].fave <<
            endl;
    }

}

//img read write
void img_read_wirte_test(char* fname)
{
    ifstream fin;
    ofstream fout;

    char buf[100000];
    string str;

    fin.open(fname, ios::binary);
    fin.seekg(0, ios::end);
    int sz = fin.tellg();
    cout << "img size: " << sz << endl;
    fin.seekg(0, ios::beg);
    fin.read(buf, sz);
    fin.close();

    fout.open("../data/img_copy.png", ios::binary);
    fout.write(buf, sz);
    fout.close();
}

void binary_test(char* fname)
{
    ifstream fin; //read file
    ofstream fout;//write file
    char buf[15];
    //test code 
    sStudent sInfo;
    sInfo.name = "홍길동";
    sInfo.kor = 100;
    sInfo.eng = 40;
    sInfo.mat = 80;
    sInfo.itotal = 0;
    sInfo.fave = 0.0f;
    fout.open(fname, ostream::binary | ostream::out);
    if (!fout) //열기 실패시 
    {
        cerr << "쓰기용 파일 열기 실패!" << endl;
        exit(1);
    }
    //열기 성공시 
 //   for (int i = 0; i < 10; i++)
 //   {
 //       fout.write((char*)&i, sizeof(int));
 //   }
    strcpy_s(buf, sInfo.name.c_str());
    fout.write((char*)buf, sizeof(buf));
    fout.write((char*)&sInfo.kor, sizeof(int));
    fout.write((char*)&sInfo.eng, sizeof(int));
    fout.write((char*)&sInfo.mat, sizeof(int));
    fout.write((char*)&sInfo.itotal, sizeof(int));
    fout.write((char*)&sInfo.fave, sizeof(float));

    fout.close();
    /*
if(0) //내부를 실행하지 않음, 조건이 거짓 == 0 이니까
{ }
if(1) //내부{}를 실행함 . 조건이 참==1이니까
{ }
*/
    fin.open(fname, ostream::binary | ostream::in);
    if (!fin)//읽기 실패하면 
    {
        cerr << "읽기 파일 열기에 실패!!" << endl;
        exit(1);
    }
    int n;
    /*/
    for (int i = 0; i < 10; i++)
    {
        fin.read((char*)&n, sizeof(int));
        cout << n << endl;
    }
    */
    sStudent sDisplay;

    fin.read((char*)&buf[0], sizeof(buf));
    fin.read((char*)&sDisplay.kor, sizeof(int));
    fin.read((char*)&sDisplay.eng, sizeof(int));
    fin.read((char*)&sDisplay.mat, sizeof(int));
    fin.read((char*)&sDisplay.itotal, sizeof(int));
    fin.read((char*)&sDisplay.fave, sizeof(float));

    sDisplay.name = buf;

    cout << sDisplay.name << " " <<
        ", eng : " << sDisplay.eng <<
        ", kor : " << sDisplay.kor <<
        ", mat : " << sDisplay.mat <<
        ", itotal : " << sDisplay.itotal <<
        ", fave : " << sDisplay.fave <<
        endl;
    fin.close();




}