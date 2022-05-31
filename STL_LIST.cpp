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
	mitem[0] = "창";
	mitem[1] = "포션";
	mitem[3] = "독약";
	mitem[4] = "방패";
	mitem[10] = "지도";
	mitem[11] = "황금";
	mitem[100] = "동검";
	mitem[101] = "철검";
	mitem[500] = "유물";
	mitem[501] = "고대유물";
	mitem.insert({ 2, "검" });
	for (auto it = mitem.begin(); it != mitem.end(); it++)
	{
		cout << it->first << ", " << it->second << endl;
	}

	for (int myitem : myinventory)
	{
		cout << mitem[myitem] << endl;
	}
}