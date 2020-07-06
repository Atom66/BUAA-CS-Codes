#include <cstdio>
#include <cstring>
const int maxn = 1010;

int father[maxn];

struct member {
    char name[maxn];
    int depth;
}m[maxn], temp;

int main() {
    int i = 3, j, k;
    char check;
    scanf("%s %s %s", m[0].name, m[1].name, m[2].name);
    m[0].depth = 1;
    m[1].depth = m[2].depth = 2;
    father[1] = father[2] = 0;
    while(1) {
        scanf("%*c%s %s%c", temp.name, m[i++].name, &check);
        //�ҳ�temp���ڵı��
        for(j = 0; j < i - 1; j++) {
            if(strcmp(temp.name, m[j].name) == 0) {
                break;
            }
        }
        if(check == '\n') break; //������ֻ�������ͻ���ʱ���˳�ѭ������ʼ���
        scanf("%s", m[i++].name); //�����ǣ�����ɨ�����������
        //����丸�׺������Ϣ
        father[i - 2] = father[i - 1] = j;
        m[i - 2].depth = m[i - 1].depth = m[j].depth + 1;
    }
    //�˳�ɨ���Ҫ����temp��m[i-1]��Ȳ�͹�ͬ�ĸ��ڵ�
    //���ҳ�m[i-1]֮ǰ���ڵı�ţ�temp���ڱ��Ϊj
    for(k = 0; k < i; k++) {
        if(strcmp(m[i - 1].name, m[k].name) == 0) {
            break;
        }
    }
    int d = m[k].depth - m[j].depth;
    if(d > 0) { //��k��j��ȸ���
        int dtemp = d;
        while(dtemp--) { //k����׷����ͬһ���
            k = father[k];
        }
        while(strcmp(m[k].name, m[j].name) != 0) { //��ͬ���ʱ���ȣ���������׷��
            k = father[k];
            j = father[j];
        }
        printf("%s %d", m[j].name, d); //�����ʱ�Ĺ�ͬ��㣬��ԭ��Ȳ�
    }
    else { //��ǰ�߱Ⱥ�����ȸ���
        int dtemp = -d;
        while(dtemp--) { //׷����ͬһ���
            j = father[j];
        }
        while(strcmp(m[k].name, m[j].name) != 0) { //��ͬ���ʱ���ȣ���������׷��
            k = father[k];
            j = father[j];
        }
        printf("%s %d", m[j].name, -d); //�����ʱ�Ĺ�ͬ��㣬��ԭ��Ȳ�
    }
    return 0;
}
