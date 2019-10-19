#define MAXX 30
#define MAXY 16
#define refresh_time 200 // time in ms

#include <time.h>
#include <curses.h>
#include <unistd.h>
#include <utility>
#include <iostream>

#include <chrono> // time libs

class Player{
    public:
        std::chrono::steady_clock::time_point start_time;
        int x, y; // coordenadas 
        int updown, leftright; // -1 - up; 1 - down; -1 - left; 1 - right
        Player(){
            start_time = std::chrono::steady_clock::now();
            updown = -1;
            leftright = -1;
            x = MAXX/2;
            y = MAXY/2;
        }
        void Update(){
            // Calculates time difference
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();

            if(y == 1 && updown == -1){
                updown = 1;
            }else if(y == MAXY-1 && updown == 1){
                updown = -1;
            }
            if(x == 0 && leftright == -1){
                x = MAXX-1;
            }else if(x == MAXX && leftright == 1){
                x = 1;
            }

            if(elapsed < refresh_time){
                return;
            }
            start_time = std::chrono::steady_clock::now();

            y += updown;
            x += leftright; 
            if(x == 0 && leftright == -1){
                x = MAXX-1;
            }else if(x == MAXX && leftright == 1){
                x = 1;
            }
        }

        void change_dir(char key){
            if(key == 'l')
                leftright = -1;
            else if (key == 'r')
                leftright = 1;
        }
};

class Window{
    public:
        Window(){
            int len = (1 + MAXX - 15)/2;
            int i;

            char wall = '#';

            for(i=0;i<len+1/2;i++)
                mvaddch(0, i, wall);

            mvaddstr(0, i, "Super Gravitron");
            for(i=15+len;i<=MAXX;i++)
                mvaddch(0, i, wall);

            for(int i=1;i<MAXY;i++){
                mvaddch(i, 0, wall);
                mvaddch(i, MAXX, wall);
            }
            for(int i=0;i<=MAXX;i++)
                mvaddch(MAXY, i, wall);
        }

        void Update(Player P, std::pair<int, int> pastPlayer){

            mvaddch(pastPlayer.second, pastPlayer.first, ' ');
            mvaddch(P.y, P.x, 'X');
            refresh();
        }
};

#include <stdio.h>

int main(){
    // Curses
    initscr();
    cbreak();
    noecho();

    clear(); // limpa tela

    Player P;
    std::pair <int, int> coord;

    int pastx, pasty;

    Window W;

    while(true){
        //printf("%d %d\n", P.x, P.y);
        //sleep(1);
        coord = std::make_pair(P.x, P.y);
        P.Update();

        // Renders Window
        W.Update(P, coord);
    }

    return 0;
}
