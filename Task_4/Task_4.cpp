#include "stdafx.h"
#include<forward_list>
#include<list>
#include<iterator>
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	forward_list<int> flst;
	cout << "¬ведите целое число больше 1: \n";
	int l = 0;
	while (cin >> l)
	{
		flst.clear();
		for (; l > 0; --l)
		{
			flst.push_front(l);
		}
		int hsize = (distance(flst.begin(), flst.end())) / 2 + 1;
		auto pos = flst.begin();
		for (int i = 0; i <= hsize; ++i, --hsize)
		{
			auto rpos = flst.begin();
			auto rrpos = flst.before_begin();
			for (; next(rpos) != flst.end(); ++rpos, ++rrpos);
			flst.insert_after(pos, rpos, flst.end());
			flst.erase_after(rrpos);
			if (l <= 3)
				break;
			else
				++(++pos);
		}
		for (auto a : flst)
		{
			cout << a;
		}
		cout << "\n¬ведите целое число: \n";
	}
	cin.get();
	return 0;
}

