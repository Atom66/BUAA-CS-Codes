
//15:30-16:08
#include <cstdio>

char str[1000010]; //�����¼��str��

struct ENUM { //enum�����ڽṹ�壬����������ֵ������һ��
    char name[1010];
    int num;
}e[1010];

int main() {
    scanf("%s", str);
    int i = 3, j = 0, k = 0;
    while(str[++i] != '{'); //���ҵ��������õġ�{����Ϊ��ʼ
    while(str[i++] != '}') { //����ʱ��Ϊ��}����һֱѭ����¼������
        while(str[i] != '=' && str[i] != ',' && str[i] != '}') { //ѭ����ֵ��Ŀ��
            e[j].name[k++] = str[i++];
        }
        if(str[i] == '=') { //����Ⱥ��˳����������¼�����ֵ
            int sum = 0;
            while(str[++i] >= '0' && str[i] <= '9') {
                sum = sum * 10 + str[i] - '0';
            }
            e[j].num = sum;
        }
        else { //����Ϊǰһ��ֵ+1����һ��Ĭ��Ϊ0
            if(j == 0) e[j].num = 0;
            else e[j].num = e[j - 1].num + 1;
        }
        j++; //���ۺ����������¼��һ����ǰͳһ����j++
        k = 0; //�Լ�����k����
    }
    for(i = 0; i < j; i++) { //��ӡ���е�enum��Ŀ����ֵ
        printf("%s %d\n", e[i].name, e[i].num);
    }
    return 0;
}
