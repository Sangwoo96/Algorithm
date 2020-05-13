#include <iostream>
#include <string>
using namespace std;
#define MAX 35
//s ����, r ����, p ��
int main() {
	int tc; cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n; cin >> n;
		string s[MAX];
		int rsp[3]; //�� ���帶�� ������������ ����
		bool alive[MAX]; //1����, -1Ż��
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			alive[i] = true;
		}
		int k = s[1].size(); //���ڿ� ���� ��, �ؾ��ϴ� ���� ��
		for (int i = 0; i < k; i++)//����
		{
			for (int j = 0; j < 3; j++) rsp[j] = 0;
			for (int j = 1; j <= n; j++) {
				if (!alive[j]) continue;
				if (s[j][i] == 'R') rsp[0] = 1;
				else if (s[j][i] == 'S') rsp[1] = 1;
				else if (s[j][i] == 'P') rsp[2] = 1;
			}
			if (rsp[0] + rsp[1] + rsp[2] == 2) {
				char lose_char;
				if (rsp[0] == 0) lose_char = 'P'; // S vs P
				else if (rsp[1] == 0) lose_char = 'R'; // P vs R
				else if (rsp[2] == 0) lose_char = 'S'; // R vs S
				for (int j = 1; j <= n; j++)
					if (s[j][i] == lose_char)
						alive[j] = false;
			}
		}
		int cnt = 0, tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (alive[i]) {
				tmp = i; cnt++;
			}
		}
		if (cnt > 1) cout << "0" <<endl;
		else cout << tmp << endl;
	}
	return 0;
}