#include <iostream>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
struct info
{
	LL num;
	LL x, y;
};
struct Rule
{
	bool operator()(const info &i1, const info &i2)const
	{
		if (i1.num == i2.num)
		{
			if (i1.x == i2.x)return i1.y < i2.y ? true : false;
			else return i1.x < i2.x ? true : false;
		}
		else return fabs(i1.num) > fabs(i2.num) ? true : false;
	}
};
int main()
{
	//freopen("in.txt", "r", stdin);

	multiset<info, Rule> st;
	LL flag = 0;
	while (1) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 4; j++)
			{
				info tmp;
				if (cin >> tmp.num)
				{
					tmp.x = i; tmp.y = j;
					st.insert(tmp);
					continue;
				}
				else if (i == 0 && j == 0)
				{
					flag = 1;
					break;
				}
			}
		if (flag)break;
		auto p = st.begin();
		cout << fabs(p->num) << " " << p->x + 1 << " " << p->y + 1 << endl;
	}
	return 0;

}

