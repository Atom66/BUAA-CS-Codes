

//12:40
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct STR { //ʹ�ýṹ�������ά���飬��������
    char s[105];
}str[1010];

int num = 0;

bool judgeExist(char b[]) { //�жϴ˵����Ƿ��Ѿ���¼��
    for(int i = 0; i < num; i++) {
        if(strcmp(str[i].s, b) == 0)
            return true;
    }
    return false;
}

bool judgeChar(char c) { //�ж��Ƿ�ΪӢ���ַ�
    if(c >= 'a' && c <= 'z')
        return true;
    else return false;
}

bool cmp(STR a, STR b) { //�Խṹ�尴�ֵ�������
    return strcmp(a.s, b.s) < 0;
}

int main() {
    char a[100010], temp[105];
    while(gets(a) != NULL) {
        int i = 0, j = 0;
        while(i < strlen(a)) { //��i��Ϊĩβʱ�ظ�ѭ��
            while(i < strlen(a) && judgeChar(a[i])) { //��ΪӢ����ĸʱ����¼����
                temp[j++] = a[i++];
            }
            if(j && !judgeExist(temp)) { //��j��Ϊ0����δ���ֹ����򽫸õ���copy����¼�ṹ����
                temp[j++] = '\0'; //����ϰ�߸��ַ����ӽ�β�ַ�
                strcpy(str[num++].s, temp);
            }
            memset(temp, 0, sizeof(temp));
            j = 0;
            while(i < strlen(a) && !judgeChar(a[i])) i++;
        }
    }
    sort(str, str + num, cmp);
    for(int i = 0; i < num; i++) {
        printf("%s\n", str[i].s);
    }
    return 0;
}


/*���ʹ�������
char str[1010][1010];
bool cmp(char a[], char b[]) {
    return strcmp(a, b) < 0;
}
sort(str, str + num, cmp);

*/
/*
//15:19-15:30
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int main() {
    char a[100010];
    set<string> s;
    while(gets(a) != NULL) {
        int i = 0;
        while(i < strlen(a)) {
            string temp; //ÿ��ʹ��ÿ�ζ��壬�൱����յĲ���
            while(i < strlen(a) && a[i] >= 'a' && a[i] <= 'z') {
                temp += a[i++];
            }
            s.insert(temp);
            while(i < strlen(a) && (a[i] < 'a' || a[i] > 'z')) i++;
        }
    }
    for(set<string>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
*/
