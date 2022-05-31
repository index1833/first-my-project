#include <iostream>
#include <list>
#include <map>
using namespace std;

int main()
{
	cout << "title : stl-list" << endl;
	
	list<int> totallist, myinventory;//
	totallist.push_back(0);
	totallist.push_back(1);
	totallist.push_back(2);
	totallist.push_back(3);
	totallist.push_back(4);
	totallist.push_back(10);
	totallist.push_back(11);
	totallist.push_back(100);
	totallist.push_back(101);
	totallist.push_back(500);
	totallist.push_back(501);

	myinventory.push_back(0);
	myinventory.push_back(4);
	myinventory.push_back(100);


	cout << "size: " << myinventory.size() << endl;
	
	map<int, string> mitem;
	mitem[0] = "â";
	mitem[1] = "����";
	mitem[3] = "����";
	mitem[4] = "����";
	mitem[10] = "����";
	mitem[11] = "Ȳ��";
	mitem[100] = "����";
	mitem[101] = "ö��";
	mitem[500] = "����";
	mitem[501] = "�������";
	mitem.insert({ 2, "��" });
	for (auto it = mitem.begin(); it != mitem.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}

	for (int myitem : myinventory)
	{
		cout << mitem[myitem] << endl;
	}
}