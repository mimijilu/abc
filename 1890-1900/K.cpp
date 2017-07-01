#include<bits/stdc++.h>
using namespace std;
int T;
struct Player {
	char card[5][4];
	int s[17], level; // s[i]Ϊ��i��������levelΪ���͵ȼ�
	bool straight, flush; // �Ƿ�Ϊ˳�Ӻ�ͬ��
} ushio, tomoya;
void init() { // ��ʼ��
	memset(&ushio, 0, sizeof(ushio));
	memset(&tomoya, 0, sizeof(tomoya));
}
void scan() { // ��������
	for (int i=0; i<5; ++i) scanf("%s", ushio.card[i]);
	for (int i=0; i<5; ++i) scanf("%s", tomoya.card[i]);
}
int getNum(char card[]) {
	if (card[0] == '1') return 10;
	if (card[0] == 'J') return 11;
	if (card[0] == 'Q') return 12;
	if (card[0] == 'K') return 13;
	if (card[0] == 'A') return 14;
	if (card[0] <= '9') return card[0]-'0'; // ע��1ҲС��9
}
bool isFlush(Player p) {
	char suit;
	if (p.card[0][0] == '1') suit = p.card[0][2];
	else suit = p.card[0][1];
	for (int i=1; i<5; ++i) {
		if (p.card[i][0] == '1') {
			if (p.card[i][2] != suit) return false;
		} else {
			if (p.card[i][1] != suit) return false;
		}
	}
	return true;
}
bool isStraight(Player p) {
	for (int i=2; i<11; ++i) 
		if (p.s[i]==1 && p.s[i]==p.s[i+1] && p.s[i]==p.s[i+2] 
		 && p.s[i]==p.s[i+3] && p.s[i]==p.s[i+4]) return true;
	return false;
}
void calLevel1(Player &p) { // ����˳�Ӻ�ͬ�������ж����͵ȼ�
	if (isFlush(p)) p.flush = true;
	if (isStraight(p)) p.straight = true;
	if (p.flush && p.straight) p.level = 9; // ͬ��˳
	else if (p.flush) p.level = 6; // ͬ��
	else if (p.straight) p.level = 5; // ˳��
	else p.level = 1; // �ȼ���Ϊ�޶�
}
void calLevel2(Player &p) { // �������ظ��Ƶ�������һ���������͵ȼ�
	int three=0, two=0;
	for (int i=2; i<15; ++i) { // ͳ���ظ����Ƶ�����
		if (p.s[i] == 4) p.level = max(p.level, 8), p.s[16]=i, p.s[i]=0; // ����
		if (p.s[i] == 3) p.level = max(p.level, 4), p.s[16]=i, p.s[i]=0, ++three; // ����
		if (p.s[i] == 2) { // һ��
			p.level = max(p.level, 2); 
			if (!p.s[15]) p.s[15] = i;
			else p.s[16] = i;
			p.s[i]=0, ++two; 
		}
	}
	if (three && two) p.level = max(p.level, 7); // ���ú�
	if (two == 2) p.level = max(p.level, 3); // ����
}
void deal() { // ��������
	for (int i=0; i<5; ++i) { // ͳ�Ʋ�ͬ�Ƴ��ִ���
		++ushio.s[getNum(ushio.card[i])];
		++tomoya.s[getNum(tomoya.card[i])];
	}
	calLevel1(ushio); calLevel1(tomoya); // ����˳�Ӻ�ͬ�������ж����͵ȼ�
	calLevel2(ushio); calLevel2(tomoya); // �������ظ��Ƶ�������һ���������͵ȼ�
}
int compare() {
	if (ushio.level > tomoya.level) return 1;
	else if (ushio.level < tomoya.level) return -1;
	else {
		for (int i=16; i>=2; --i) {
			if (ushio.s[i] > tomoya.s[i]) return 1;
			if (ushio.s[i] < tomoya.s[i]) return -1;
		}
		return 0;
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		init();	scan(); deal(); // ��ʼ�������벢����
		int ans = compare();
		if (ans > 0) puts("Ushio shouri!");
		else if (ans < 0) puts("Papa shouri!");
		else puts("Mama!");
	}
	return 0;
}
