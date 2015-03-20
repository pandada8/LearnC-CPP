#include <stdio.h>
#include <stdlib.h>
#ifdef __WINDOWS_
    #include <conio.h>
    char getControlChar(){
        return _getch();
    }
#endif // __WINDOWS_
#ifdef linux

    char getControlChar(){
        char ret;
        system("stty raw");
        ret = getchar();
        system("stty cooked");
        return ret;
    }
#endif // linux



#define H 10
#define V 10

char maze[V][H] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ',' ',' ','#',' ','#',' ','#'},
    {'#','#',' ','#',' ','#',' ','#',' ','#'},
    {'#','#',' ','#',' ','#',' ',' ',' ','#'},
    {'P',' ',' ','#',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ',' ',' ',' ','O'},
    {'#','#','#','#','#','#','#','#','#','#'}
};
char Finish= 0;
int step = 0;
int x = 4, y = 0;
void draw(){
    int i,j;
    system("cls");
    for (i = 0;i < V; i++){
        for(j = 0; j < H;j++ ){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("Steps: %d\n", step);
}

void move(int h, int v){
    char target;
    target = maze[x + v][y + h];
    switch(target){
    case ' ':
        step ++;
        maze[x+v][y+h] = 'P';
        maze[x][y] = ' ';
        x += v;
        y += h;
        draw();
        break;
    case 'O':
        Finish = 1;
        step ++;
        maze[x+v][y+h] = 'P';
        maze[x][y] = ' ';
        x += v;
        y += h;
        draw();
        printf("You Win!");
        break;
    case '#':
    default:
        return;
    };

}
int main(){
    // start main loop
    char control;
    draw();
    while (control = getControlChar()){
        putchar(control);
        switch(control){
        case 'W':
        case 'w':
            move(0, -1);
            break;
        case 's':
        case 'S':
            move(0, 1);
            break;
        case 'a':
        case 'A':
            move(-1, 0);
            break;
        case 'D':
        case 'd':
            move(1, 0);
            break;
        case 'q':
        case 'Q':
            printf("Good bye!");
            return 0;
        default:
            draw();
        }
    };
    return 0;
}

