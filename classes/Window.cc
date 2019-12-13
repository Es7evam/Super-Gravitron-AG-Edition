#include "Window.hh"

Window::Window() {
    int i;
    _lastblast = std::chrono::steady_clock::now();

    char wall = '#';

    for(i=0;i<=MAXX;i++) {
        mvaddch(0, i, wall);
        mvaddch(MAXY, i, wall);
    }

    for(int i=1;i<MAXY;i++){
        mvaddch(i, 0, wall);
        mvaddch(i, MAXX, wall);
    }

    mvaddstr(0, 3, " Super Gravitron - Score:   ");
}

bool Window::Update(Player P, std::vector<Blast>* B, std::pair<int, int> pastPlayer) {

    // Rendering Blasts
    for(unsigned long int i = 0; i < B->size(); i++){
        //std::cerr << " Past "<< "[" << (*B)[i].pastx() << "," << (*B)[i].y() << "]" << "; New:" << "[" << (*B)[i].x() << "," << (*B)[i].y() << "]" << std::endl;
        mvaddch((*B)[i].pasty(), (*B)[i].pastx(), ' ');
        mvaddch((*B)[i].y(), (*B)[i].x(), '*');

        if((*B)[i].ended() == true){
            mvaddch((*B)[i].y(), (*B)[i].x(), '#');
            (*B).erase((*B).begin()+i);
        }
    }
    

    std::string s = std::to_string((float)P.score()/1000.0).substr(0,4);
    char const *pchar = s.c_str();
    mvaddstr(0, MAXX-3, pchar);

    // Rendering Player
    mvaddch(pastPlayer.second, pastPlayer.first, ' ');
    mvaddch(P.y(), P.x(), 'X');


    // Generating new Blast
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastblast).count();
    if(elapsed > bullet_time){
        //std::cerr << "Gerou blast " << std::endl;
        Blast* newBlast;
        newBlast = new(Blast);
        _lastblast = now;
        B->push_back((*newBlast));
    }
    bool ret = Collided(P, *B);
    refresh();

    return ret;
}

bool Window::Collided(Player player, std::vector<Blast> B){
    bool collision = false;
    for(auto blast: B){
        //for(auto player : P){
        if(player.x() == blast.x() && player.y() == blast.y()){
            collision = true;
            //std::cerr << "Cabo o joguin" << std::endl;
            EndGame();
        }
        //}
    }
    return collision;
}

void Window::EndGame(){

    char wall = 'O';
    int len = (1 + MAXX - 10)/2;
    int i;
    int writeY = MAXY+3;

    // Parede superior 
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY, i, wall);
    }
    
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY+1, i, wall);
    }
    mvaddstr(writeY+1, len, " You Lose ");
    
    for(i=0;i<=MAXX;i++) {
        mvaddch(writeY+2, i, wall);
    }
    //refresh();
    //while(1);

}
