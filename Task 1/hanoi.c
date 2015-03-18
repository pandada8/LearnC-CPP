#include <stdio.h>

/*
 * 汉诺塔问题
 * 先把A塔顶部的N-1块盘移动到B塔，再把A塔剩下的大盘移到C，最后把B塔的N-1块盘移到C
 * */

void move(int level, char from, char to, char dependency){
    if (level == 1) printf("%c -> %c\n", from, to);
    else{
        // 首先移到B
        move(level - 1, from, dependency, to);
        // 可以将最下面的移到C
        printf("%c -> %c\n", from , to);
        move(level-1, dependency, to, from);
    }
}

int main(){
    int n = 0;
    printf("levels :");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    return 0;
}
