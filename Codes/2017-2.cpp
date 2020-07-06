/*
//д�������֮����������ģ�û�취д����������
//ָ���ȡ��ֱַ���군�ˡ�
#include <cstdio>
#include <cstring>
const int maxn = 1000000;

char str[maxn], temp[1000];
char sub[1000][1000];
int cnt1 = 0, cnt2 = 0;

void deal() {
    for(int i = 0; i < strlen(str) && str[i] != ';'; ) {
        while(str[i] != ',' && str[i] != '=' && str[i] != ';' && str[i] != ' ' && str[i] != '[') {
            sub[cnt1][cnt2++] = str[i];
            i++;
        }
        sub[cnt1][cnt2] = '\0';
        cnt1++;
        cnt2 = 0;
        if(str[i] == '=' || str[i] == '[') { //�����ȺŻ������ʱ������֮���һ���ַ�ֱ�����Ż�ֺ�
            while(str[i] != ',' && str[i] != ';') {
                i++;
            }
        }
        if(str[i] == ',') { //�������ŵ�ʱ������֮���һ�пո�
            i++;
        }
        while(str[i] == ' ') { //�����ո��ʱ������֮��һ�пո�
            i++;
        }
        //�����ֺŵ�ʱ���Զ�����ѭ��
    }
}

bool check() {
    for(int i = 0; i < cnt1; i++) {
        if(strcmp(temp, sub[i]) == 0) {
            return true;
        }
    }
    return false;
}

void deal2() {
    for(int i = 0; i < strlen(str) && str[i] != ';'; i++) {
        while(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '%' && str[i] != '=') {
            if(str[i] == ' ') {
                i++;
                continue;
            }
            temp[cnt2++] = str[i];
            i++;
        }
        temp[cnt2] = '\0';
        if(!check()) {
            printf("%s ", temp);
        }
        memset(temp, 0, sizeof(temp));
        cnt2 = 0;
    }
}

int main() {
    gets(str);
    deal();
    gets(str);
    deal2();
    return 0;
}
*/

#include <cstdio>
#include <cstring>

const int maxn = 1010;
char str[maxn * maxn];
char sub[maxn][maxn];
int cnt1 = 0, cnt2 = 0;

bool judge(char c) { //�ж��ַ��Ƿ�Ϊ�Ϸ�����������ֻ������ĸ���»��ߡ�����
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9') || c == '_') return true;
    else return false;
}

void deal() { //��str���д��������еĺϷ���������˳�����sub��
    int i = 0, len = strlen(str);
    while(str[i] != ' ') i++; //��������ı������ͣ��Ⱥ��Ա�������
    while(i < len) { //��i������Χʱ�˳�ѭ����Ҳ�����жϷֺţ�
        while(i < len && !judge(str[i])) i++; //�������еĲ��Ϸ��ַ���ֱ��i������Χ���������Ϸ����ַ�
        while(str[i] >= '0' && str[i] <= '9') i++; //���ڷǷ��ַ����������֣���Ϊ�����������¼
        while(judge(str[i])) { //����������������͵��ַ���ѭ����¼��sub��
            sub[cnt1][cnt2++] = str[i++];
        }
        //�����ַ�����ĩβ������cnt1������cnt2���㣬׼��������һ���ַ�
        sub[cnt1][cnt2] = '\0';
        cnt1++, cnt2 = 0;
    }
}

bool defined(char temp[]) { //���������Ƿ��Ѿ������
    for(int j = 0; j < cnt1; j++) {
        if(strcmp(temp, sub[j]) == 0) return true;
    }
    return false;
}

void deal2() {
    int i = 0, len = strlen(str);
    while(i < len) {
        char temp[maxn]; //���Ƶأ�����Ϸ�������������temp����ѭ���ж�����Ա���������鷳
        while(i < len && !judge(str[i])) i++; //��i������Χʱ�˳�ѭ������һ���зֺ�
        while(str[i] >= '0' && str[i] <= '9') i++; //���ڷǷ��ַ����������֣���Ϊ�����������¼
        while(judge(str[i])) { //����������������͵��ַ���ѭ����¼��temp��
            temp[cnt2++] = str[i++];
        }
        temp[cnt2] = '\0', cnt2 = 0;
        if(!defined(temp)) { //��tempδ���壬��ӡtemp
            printf("%s ", temp);
        }
    }
    printf("\n");
}

int main() {
    gets(str);
    deal();
    gets(str);
    deal2();
    return 0;
}









