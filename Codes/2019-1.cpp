#include <cstdio>

const int maxn = 100010;

bool hashTable[maxn] = {false};
int prime[maxn], pNum = 0;

//ʹ�ð�ʽɸ����ӡ������
void FindPrime() {
    hashTable[1] = true; //������Ϊ1��������
    for(int i = 2; i < maxn; i++) {
        if(hashTable[i] == false) {
            prime[pNum++] = i;
            for(int j = 2 * i; j < maxn; j += i) {
                hashTable[j] = true;
            }
        }
    }
}

int main() {
    FindPrime(); //��ʼ��������
    int a, b;
    scanf("%d %d", &a, &b);
    //�ҵ���a��ʼ�ĵ�һ������
    int first;
    for(int i = 0; ; i++) {
        if(prime[i] >= a) {
            first = i;
            break;
        }
    }
    //��first��ʼ���ۣ��俪ʼ�����������Ƿ�Ϊ�Ȳ����У���prime[i + 2] > bʱ��i+2�����������������ʱ�˳�ѭ��
    for(int i = first; i + 2 <= pNum && prime[i + 2] <= b; i++) {
        if(prime[i] + prime[i + 2] == 2 * prime[i + 1]) {
            printf("%d %d %d ", prime[i], prime[i + 1], prime[i + 2]);
            //�������ж��Ƿ������������������������ǰ��i��++����ѭ���жϲ������ظ����
            while(prime[i + 1] + prime[i + 3] == 2 * prime[i + 2] && i + 3 <= pNum && prime[i + 3] <= b) {
                printf("%d ", prime[i + 3]);
                i++;
            }
            printf("\n");
        }
    }
    return 0;
}
