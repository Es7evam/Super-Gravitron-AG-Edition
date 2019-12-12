#include "AG.hh"

AG::AG(){
    _moveQuantity = _currentMove = _maxScore = 0;
    _threshold = 10;
    _bias = 10;
    enabled = false;
}

void AG::save(){
    _movements.clear();
    FILE *fp;
    fp = fopen("best.txt", "w");
    fprintf(fp, "%d %d\n", (int)_movements.size(), _maxScore);
    for(int i=0;i<(int)_movements.size();i++){
        fprintf(fp, "%d %d\n", _movements[i].first,  _movements[i].second);
    }
    fclose(fp);
}

void AG::load(){
    int direction, moveTime;
    FILE *fp;
    fp = fopen("best.txt", "r");
    fscanf(fp, "%d %d", &_moveQuantity, &_maxScore);
    for(int i=0;i<_moveQuantity;i++){
        fscanf(fp, "%d %d", &direction, &moveTime);
        _movements.push_back(std::make_pair(direction, moveTime));
    }
    fclose(fp);
}

int AG::makeMove(Player P){
    // até moveCount ser quase igual a _moveQuantity, move seguindo _movements

    std::pair<int, int> newMove;
    int direction;

    // Copia movimento antigo
    if(_currentMove < _moveQuantity - _threshold){
        direction = _movements[_currentMove].first;
        newMove = std::make_pair(direction, _currentMove); 
    }else{ //Faz um movimento novo
        direction = (rand()%(_bias+2));
        if(direction == 0){
            direction = 122; //esquerda
        }else if(direction == 1){
            direction = 120; //direita
        }else{
            direction = 0; //não move
        }
        
        newMove = std::make_pair(direction, _currentMove);
        _movements.push_back(newMove);
    }
    _currentMove++;
    // se chegou no threshold tenta mover

    return direction;
}

void AG::endGame(Player P){
    // Get Score Information
    _moveQuantity = (int)_movements.size();
    _maxScore = std::max(_maxScore, P.score());

    save();
}
