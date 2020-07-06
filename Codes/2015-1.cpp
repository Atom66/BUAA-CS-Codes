/*
//10:27 �����汾
#include <cstdio>
#include <cstring>

int f[1000];
int fNum = 0;

void findFactor(int x) { //��x���������ӣ���������f[]�У�����ΪfNum��
    for(int i = 2; i <= x / 2; i++) {
        if(x % i == 0) {
            f[fNum++] = i;
        }
    }
}

int main() {
    int a, b, sum1 = 1, sum2 = 1;
    scanf("%d %d", &a, &b);
    //��a�����Ӳ���͡���ӡ
    findFactor(a);
    printf("%d, 1", a);
    for(int i = 0; i < fNum; i++) {
        printf("+%d", f[i]);
        sum1 += f[i];
    }
    printf("=%d\n", sum1);
    //���f��fNum��Ϊ��b��׼��
    memset(f, 0, sizeof(f));
    fNum = 0;
    //��b�����Ӳ���͡���ӡ
    findFactor(b);
    printf("%d, 1", b);
    for(int i = 0; i < fNum; i++) {
        printf("+%d", f[i]);
        sum2 += f[i];
    }
    printf("=%d\n", sum2);
    if(sum1 == b && sum2 == a) printf("1\n");
    else printf("0\n");
    return 0;
}
*/
/*
//ʧ�ܷ���
#include <cstdio>
#include <cmath>

const int maxn = 100000;
int prime[10000], pNum = 0, num = 0; //pNumΪ����������numΪ�����Ӹ���
int a, b, sum, sum1, sum2; //sum���ڵݹ麯���ڣ�sum1��Ӧa��ȫ�������Ӻͣ�sum2��Ӧb��
bool p[maxn] = {false};

struct factor {
    int x, cnt;
}fac[1000];

void Find_Prime() {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            prime[pNum++] = i;
            for(int j = 2 * i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

void Find_Factor(int y) {
    for(int i = 0; i < pNum && prime[i] <= sqrt(y); i++) {
        if(y % prime[i] == 0) {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while(y % prime[i] == 0) {
                y /= prime[i];
                fac[num].cnt++;
            }
            num++;
        }
    }
    if(y != 1) {
        fac[num].x = y;
        fac[num++].cnt = 1;
    }
}

//�ݹ��ӡȫ�����Ӳ����
void printSum(int layer, int product, int x) { //�ڼ������ӡ���ǰ�˻�����ʱ�ֽ����
    if(layer == num && product != 1 && product != x) {
        printf("+%d", product);
        sum += product;
    }
    for(int i = 0; i <= fac[layer].cnt; i++) {
        product *= pow(fac[layer].x, i);
        printSum(layer + 1, product, x);
        product /= pow(fac[layer].x, i);
    }
}

int main() {
    Find_Prime(); //��ӡ������
    scanf("%d %d", &a, &b);
    Find_Factor(a);
    printf("%d 1", a);
    sum = 1;
    printSum(0, 1, a);
    printf("\n");
    sum1 = sum;

    Find_Factor(b);
    printf("%d 1", b);
    sum = 1;
    printSum(0, 1, b);
    printf("\n");
    sum2 = sum;
    if(sum1 == b && sum2 == a) printf("1\n");
    else printf("0\n");
    return 0;
}
*/

//���Ű汾
#include<cstdio>

int a, b, suma = 1, sumb = 1;

int main(){
	scanf("%d%d", &a, &b);
	printf("%d, 1", a);
	int i;
	for(i = 2; i <= a / 2; i++){
		if(a % i == 0) {
			suma += i;
			printf("+%d", i);
		}
	}
	printf("=%d\n", suma);
	printf("%d, 1", b);
	for(i = 2; i <= b / 2; i++){
		if(b % i == 0) {
			sumb += i;
			printf("+%d", i);
		}
	}
	printf("=%d\n", sumb);
	if(suma == b && sumb == a) printf("1\n");
	else printf("0\n");
	return 0;
}

