#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	int ruCnt = (n-1) / 14 + 2; // ruru의 개수. 처음엔 2, 그다음은 3, ...
	int pos = (n-1) % 14; // 단어의 종류. 한 문단에 단어는 14종류.

	switch (pos)
	{
	case 0:
	case 12:
		cout << "baby";
		break;
	case 1:
	case 13:
		cout << "sukhwan";
		break;
	case 2:
	case 6:
	case 10:
		if (ruCnt < 5)
		{
			cout << "tu";
			for (int i = 0; i < ruCnt; ++i)
			{
				cout << "ru";
			}
		}
		else
		{
			cout << "tu+ru*" << ruCnt;
		}
		break;
	case 3:
	case 7:
	case 11:
		if (ruCnt-1 < 5)
		{
			cout << "tu";
			for (int i = 0; i < ruCnt-1; ++i)
			{
				cout << "ru";
			}
		}
		else
		{
			cout << "tu+ru*" << ruCnt-1;
		}
		break;
	case 4:
		cout << "very";
		break;
	case 5:
		cout << "cute";
		break;
	case 8:
		cout << "in";
		break;
	case 9:
		cout << "bed";
		break;
	default:
		break;
	}
	cout << "\n";

}
