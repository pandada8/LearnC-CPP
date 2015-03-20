#include <stdio.h>
#include <stdlib.h>
#ifdef __WINDOWS_
    #include <conio.h>
    char getControlChar(){
        return _getch();
    }
#endif // __WINDOWS_
#ifdef linux
    // this code is copied from StackOverflow
    #include <termios.h>
    #include <unistd.h>
    char getControlChar(){
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }
#endif // linux

#define VALID(a, b) (((a) >= 0) && ((a) < (b)))

#define H 10
#define V 10

char maze[V][H] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ',' ',' ','#',' ','#',' ','#'},
    {'#','#',' ','#',' ','#',' ','#',' ','#'},
    {'#','#',' ',' ',' ','#',' ',' ',' ','#'},
    {'P','O',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#',' ','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ','X'},
    {'#','#','#','#','#','#','#','#','#','#'}
};
char Finish= 0;
int step = 0;
int x = 4, y = 0;
void draw(){
    int i,j;
#ifdef __WINDOWS_
    system("cls");
#endif
#ifdef linux
    system("clear");
#endif
    for (i = 0;i < V; i++){
        for(j = 0; j < H;j++ ){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    printf("Steps: %d\n", step);
}

void move(int h, int v){
    char* target, *target_next;
    target = &maze[x + v][y + h];
    target_next = VALID(x+2*v,V) && VALID(y+2*h, H) ? &maze[x + 2 * v][y + 2 * h] : NULL;
    if (*target == ' '){
        step ++;
        *target = 'P';

        maze[x][y] = ' ';
        x += v;
        y += h;
        draw();
        return;
    }else if(*target == 'O'){
        // Wow a box!
        if (*target_next == ' '){
            // blank, go, go, go!
            step ++;
            *target = 'P';
            *target_next = 'O';
            maze[x][y] = ' ';
            x += v;
            y += h;
            draw();
            return;
        }else if (*target_next == 'X'){
            // Wow, you got it!
            step ++;
            Finish = 1;
            *target = 'P';
            *target_next = '@';
            maze[x][y] = ' ';
            x += v;
            y += h;
            draw();
            printf("You got it!");
            exit(0);
            return;
        }
    }else{
        return;
    }
}
int main(){
    // start main loop
    char control;
    draw();
    while ((control = getControlChar())){
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

