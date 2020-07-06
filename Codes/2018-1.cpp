//19:30
//20:21
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10010;
int cnt[maxn], temp = 0;
int n, s, t;

struct line {
    int sx, sy, tx, ty;
}l[maxn];

void check(int i, int now) { //���߶�i�������ۣ��鿴now֮����߶��Ƿ����߶�i�غ�
    for(int j = now + 1; j < n; j++) {
        if(l[j].sx == l[now].tx && l[j].sy == l[now].ty) { //����ʱ�غ�
            temp++;
            check(i, j);
            temp--;
        }
        else if(l[j].sx > l[now].tx) { //���Ѱ����������򣬴˾����ڼ����жϣ����Բ�д
            return;
        }
    }
    //��δ�ҵ��˳�ѭ���󣬱Ƚ�temp�Ͷ�i�ļ���������������ֵ
    //��Ȼÿ�δ�check�˳������ж�һ�£����������flag����ҵ���Ҳ���ж�һ�����Ծ�������
    if(temp > cnt[i]) {
        cnt[i] = temp;
    }
    return;
}

bool cmp(line a, line b) {
    return a.sx < b.sx;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &l[i].sx, &l[i].sy, &l[i].tx, &l[i].ty);
    }
    sort(l, l + n, cmp); //�������߶ΰ����������С��������
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) {
        check(i, i);
    }
    int MAX = -1, num;
    for(int i = 0; i < n; i++) {
        if(cnt[i] > MAX) {
            MAX = cnt[i];
            num = i;
        }
    }
    printf("%d %d %d\n", MAX + 1, l[num].sx, l[num].sy);
    return 0;
}


