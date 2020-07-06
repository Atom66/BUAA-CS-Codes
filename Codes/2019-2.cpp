




//12:50 Ԥ��14:00ֹͣ
//��Լ��13:20д�꣬debug��13:40��������ɲ���ʼдע��
//��ΪҲ��������ݵĹ�ģ���Լ��᲻��ɻ������Բ����ڽӱ�洢ͼ�ķ�ʽ
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10010;
const int inf = 0x3fffffff;

int n, m, s;
int pre[maxn];
bool vis[maxn] = {false};
bool flag; //flag=trueʱ��ʾ���ҵ�
vector<int> Adj[maxn]; //�ڽӱ�

struct client {
    int num, prior;
}c[maxn];

bool cmp(client a, client b) {
    return a.prior < b.prior;
}

void printDFS(int v) {
    if(pre[v] != -1) {
        printDFS(pre[v]);
        printf("%d ", v);
    }
}

void DFS(int s, int ed) {
    vis[s] = true; //����ʱ�ȱ���ѷ��ʣ���ֹ�ظ�����
    for(int i = 0; i < Adj[s].size(); i++) {
        int v = Adj[s][i];
        if(flag == true) return; //�����ҵ���ֱ�ӷ���
        if(vis[v] == false) { //��δ�ҵ�ʱ�ҵ�ǰv���δ�����ʹ�
            pre[v] = s; //���벢�趨v��ǰ�����Ϊs
            if(v != ed) { //����ʱv�����յ㣬����DFS����
                DFS(v, ed);
            }
            else { //�����յ�
                printDFS(pre[v]); //��ӡ��ǰ�����н�㲢�ո�
                printf("%d\n", v); //��ӡ���һ����㲢����
                flag = true; //��������ҵ�
            }
        }
    }
}

int main() {
    int f, c1, c2, c3; //father & child 1~3
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &f, &c1, &c2, &c3);
        if(i == 0) s = f;
        if(c1 != -1) {
            Adj[f].push_back(c1);
            Adj[c1].push_back(f);
        }
        if(c2 != -1) {
            Adj[f].push_back(c2);
            Adj[c2].push_back(f);
        }
        if(c3 != -1) {
            Adj[f].push_back(c3);
            Adj[c3].push_back(f);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &c[i].num, &c[i].prior);
    }
    sort(c, c + m, cmp);
    //���費���ڻ�����ô·��Ψһ��ֱ��ʹ��DFS����
    printf("%d ", s); //��ӡ��㣬�˺����ʱ������ӡ���
    for(int i = 0; i < m; i++) {
        flag = false;
        memset(pre, -1, sizeof(pre));
        memset(vis, 0, sizeof(vis));
        if(i == 0) {
            DFS(s, c[i].num);
        }
        else DFS(c[i - 1].num, c[i].num);
    }
    flag = false;
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    DFS(c[m - 1].num, s);
    return 0;
}









