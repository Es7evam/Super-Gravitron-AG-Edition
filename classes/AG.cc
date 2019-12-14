#include "AG.hh"
#include <iostream>

AG::AG(){
    _moveQuantity = _currentMove = _maxScore = 0;
    _threshold = 10;
    _bias = 10;
    enabled = false;
}

// Saves the movement vector and its parameters
void AG::save(){
    // Saves the movements vector, the max score and each movement.
    FILE *fp;
    fp = fopen("best.txt", "w");
    fprintf(fp, "%d %d\n", (int)_movements.size(), _maxScore);
    for(int i=0;i<(int)_movements.size();i++){
        fprintf(fp, "%d %d\n", _movements[i].first,  _movements[i].second);
    }
    fclose(fp);

    // Save best scores to make a chart later on
    FILE *fpChart;
    fpChart = fopen("chart.txt", "w");
    if(fpChart != NULL) {
        fprintf(fpChart, "%d\n", _maxScore);
        fclose(fpChart);
    }
}

// Loads the algorithm parameters and movements
void AG::load(){
    
    int direction, moveTime;
    FILE *fp;
    fp = fopen("best.txt", "r");
    if (fp == NULL) {
        std::cout << "No file, creating one...\n";
        save();
        fp = fopen("best.txt", "r");
    }
    // Clears the current movements vector and starts to load it
    // It trusts user input (movequantity), otherwise the program will crash
    _movements.clear();
    fscanf(fp, "%d %d", &_moveQuantity, &_maxScore);
    for(int i=0;i<_moveQuantity;i++){
        fscanf(fp, "%d %d", &direction, &moveTime);
        _movements.push_back(std::make_pair(direction, moveTime));
    }
    fclose(fp);
}

int AG::makeMove(){
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
        
        // makes a new movement in the given random direction
        // sets the movement id as the _currentMove variable
        newMove = std::make_pair(direction, _currentMove);
        _movements.push_back(newMove);
    }
    _currentMove++;
    // se chegou no threshold tenta mover

    // returns the direction the player moved after the "shuffle" 
    return direction;
}

void AG::endGame(int score){
    // Get Score Information
    _moveQuantity = (int)_movements.size();
    _maxScore = std::max(_maxScore, score);

    save();
}
