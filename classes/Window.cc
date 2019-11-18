#include "Window.hh"

Window::Window() {
    int len = (1 + MAXX - 15)/2;
    int i;
    _lastblast = std::chrono::steady_clock::now();

    char wall = '#';

    for(i=0;i<len+1/2;i++) {
        mvaddch(0, i, wall);
    }

    mvaddstr(0, i, "Super Gravitron");
    for(i=15+len;i<=MAXX;i++) {
        mvaddch(0, i, wall);
    }

    for(int i=1;i<MAXY;i++){
        mvaddch(i, 0, wall);
        mvaddch(i, MAXX, wall);
    }

    for(int i=0;i<=MAXX;i++) {
        mvaddch(MAXY, i, wall);
    }
}

void Window::Update(Player P, std::vector<Blast>* B, std::pair<int, int> pastPlayer) {
    mvaddch(pastPlayer.second, pastPlayer.first, ' ');
    mvaddch(P.y(), P.x(), 'X');

    std::cerr << "Blast window size: " << B->size() << "\n";
    for(unsigned long int i = 0; i < B->size(); i++){
        //std::cerr << " Past "<< "[" << (*B)[i].pastx() << "," << (*B)[i].y() << "]" << "; New:" << "[" << (*B)[i].x() << "," << (*B)[i].y() << "]" << std::endl;
        mvaddch((*B)[i].pasty(), (*B)[i].pastx(), ' ');
        mvaddch((*B)[i].y(), (*B)[i].x(), '*');

        if((*B)[i].ended() == true){
            mvaddch((*B)[i].y(), (*B)[i].x(), '#');
            (*B).erase((*B).begin()+i);
        }
    }
    
    // Generating new Blast
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastblast).count();
    if(elapsed > bullet_time){
        std::cerr << "Gerou blast " << std::endl;
        Blast* newBlast;
        newBlast = new(Blast);
        _lastblast = now;
        B->push_back((*newBlast));
    }
    refresh();
}

bool Window::Collided(std::vector<Player> P, std::vector<Blast> B){
    bool collision = false;
    for(auto blast: B){
        for(auto player : P){
            if(player.x() == blast.x() && player.y() == blast.y())
                collision = true;
        }
    }
    return collision;
}