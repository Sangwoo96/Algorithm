#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int h[20001];

int rect(int left, int right) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	int ret = max(rect(left, mid), rect(mid + 1, right));
	int lo = mid; int hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2); // ��ü������ �߰� ���� �ΰ��� ret�� �κ� ������ ������ ���� ret�� ��
	//�翷���� Ȯ��
	while (lo > left || hi < right) {
		if (h[lo - 1] > h[hi + 1] && lo > left) {
			--lo;
			height = min(height, h[lo]);
		}
		else {
			++hi;
			height = min(height, h[hi]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	int T = 0, N = 0;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> h[i];
		cout << rect(0, N-1) << endl;
	}
	return 0;
}