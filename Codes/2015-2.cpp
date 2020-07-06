
//10:50
#include <cstdio>

struct window {
    int rx, ry, lx, ly;
    int num, next; //��ʾ���ڱ�ź���һ�㴰��
}w[10010];

int main() {
    int n, m, click_x, click_y, top = 0; //top��ʾ��ʱ�ĵ�һ�㴰��
    int j = top, jbefore; //j��ʾ��ʱ���Ĵ��ڲ㣬jbefore���ڼ�¼����һ�㣬����֮���޸Ĳ���
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { //�������룬�����ú���һ�㴰�ڣ���ʼʱ�±�ԽСԽ����
        scanf("%d%d%d%d%d", &w[i].num, &w[i].rx, &w[i].ry, &w[i].lx, &w[i].ly);
        if(i != n - 1) {
            w[i].next = i + 1;
        }
        else w[i].next = -1; //���һ�����ڣ���������һ����Ϊ-1����ʾΪ��
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &click_x, &click_y);
        bool flag = true;
        while(click_x < w[j].lx || click_x > w[j].rx || click_y < w[j].ry || click_y > w[j].ly) { //�����ڵ�ǰ���ڷ�Χ��
            if(w[j].next > 0) { //��j����һ�����ڲ�Ϊ�գ�������ƶ�j��jbefore
                jbefore = j;
                j = w[j].next;
            }
            else flag = false; //��һ������Ϊ�գ�Ҳ���ǵ������һ�����ڣ���ô����flag��ʾʲôҲû�㵽
        }
        if(j != top && flag) { //��ʱj��Ϊ��һ��������ȷʵ�㵽��ĳ����
            w[jbefore].next = w[j].next;
            w[j].next = top;
            top = j;
        }
        //����֮�⣬�㵽��һ�����ڻ������д��ڶ�û�㵽����������Ϊʲô��û��������else
        j = top; //���½�j��ֵΪtop������㵽����j�ǲ�����top�ģ�
    }
    while(j != -1) { //ѭ����ӡ��ֱ�������һ������
        printf("%d ", w[j].num);
        j = w[j].next;
    }
    printf("\n");
    return 0;
}
