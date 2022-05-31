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
            cout << "����: " << strtemp << endl;
            cout << "����: " << iscore << endl;
            cout << "----------" << endl;
        }
    }

    readFile.close();
}

void write(char* fname)
{

    //write
    ofstream writeFile;
    writeFile.open(fname); //�����ϸ� ���� ����, �ƴϸ� ���� ����

    char arr[31] = "Item name, spece, amount\n";
    writeFile.write(arr, 30);

    string str = "mushroom, +10 force, 3ea\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //������ ���� ���Ⱑ �Ϸ���� �� �� �ֵ��� ���ش�.
    cout << "flie writing success!" << endl;
}

void writeRandomNum(char* fname)
{

    //write
    ofstream writeFile;
    writeFile.open(fname); //�����ϸ� ���� ����, �ƴϸ� ���� ����
    //random test
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 100);
    int score = distribution(gen);

    string str = std::to_string(score);
    str += "\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //������ ���� ���Ⱑ �Ϸ���� �� �� �ֵ��� ���ش�.
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
    cout << "���Ϸκ��� ���� ���ڸ� ���纸����.(1~100).. ����� 0�� �Է�" << endl;
    int iyournum = -1;
    int icount = 0;
    while (true)
    {
        cout << "����� ������ ���ڴ�? ";
        cin >> iyournum;

        if (iyournum == iscore || iyournum == 0) break;
        else if (iyournum > iscore)
        {
            cout << "������ " << iyournum << "���� �۽��ϴ�." << endl;
        }
        else
        {
            cout << "������ " << iyournum << "���� Ů�ϴ�." << endl;
        }
        icount++;
    }
    //��� ó�� 
    if (iyournum == 0)
    {
        cout << "�ƽ����� �����ϼ̱���.������ �ٽ� �����ϼ���!" << endl;
    }
    else
    {
        cout << icount << "�� ���� ������ ���߼̾��. �����մϴ�." << endl;
    }
}

void writeSchoolScore(char* fname)
{
    /*
    1. �л� 3���� 3���� ������ ���Ͽ� ����ϼ���.
�̸�   ����, ����, ����
ȫ�浿 100, 10, 20
�賲�� 20, 100, 30
�̰��� 30, 60, 100
2. ���л��� ������ ����� ���ϼ���.
3. ����� �о� ������. */
//write
    ofstream writeFile;
    writeFile.open(fname); //�����ϸ� ���� ����, �ƴϸ� ���� ����

    string str = "�̸� ���� ���� ����\n";
    writeFile.write(str.c_str(), str.size());

    str = "ȫ�浿 100 10 20\n";
    writeFile.write(str.c_str(), str.size());

    str = "�賲�� 20 100 30\n";
    writeFile.write(str.c_str(), str.size());

    str = "�̰��� 30 60 100\n";
    writeFile.write(str.c_str(), str.size());

    writeFile.close();
    //������ ���� ���Ⱑ �Ϸ���� �� �� �ֵ��� ���ش�.
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
    //��� ��� 
    student_num = 3;
    int igap = 4;
    int istart = 4;
    for (int i = 0; i < student_num; i++)
    {
        istart = igap * (i + 1);
        slist[i].name = vWordList[istart + 0];//4��° ���� ȫ�浿
        slist[i].kor = atoi(vWordList[istart + 1].c_str());//5 .. ����
        slist[i].eng = atoi(vWordList[istart + 2].c_str());//5 .. ����
        slist[i].mat = atoi(vWordList[istart + 3].c_str());//5 .. ����
        slist[i].itotal = slist[i].kor + slist[i].eng + slist[i].mat;
        slist[i].fave = slist[i].itotal / (float)student_num;
    }

    for (int i = 0; i < student_num; i++)
    {
        cout << slist[i].name <<
            ", ���� :" << slist[i].kor <<
            ", ���� :" << slist[i].eng <<
            ", ���� :" << slist[i].mat <<
            ", ���� :" << slist[i].itotal <<
            ", ��� :" << slist[i].fave <<
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
    sInfo.name = "ȫ�浿";
    sInfo.kor = 100;
    sInfo.eng = 40;
    sInfo.mat = 80;
    sInfo.itotal = 0;
    sInfo.fave = 0.0f;
    fout.open(fname, ostream::binary | ostream::out);
    if (!fout) //���� ���н� 
    {
        cerr << "����� ���� ���� ����!" << endl;
        exit(1);
    }
    //���� ������ 
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
if(0) //���θ� �������� ����, ������ ���� == 0 �̴ϱ�
{ }
if(1) //����{}�� ������ . ������ ��==1�̴ϱ�
{ }
*/
    fin.open(fname, ostream::binary | ostream::in);
    if (!fin)//�б� �����ϸ� 
    {
        cerr << "�б� ���� ���⿡ ����!!" << endl;
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