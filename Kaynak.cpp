

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
//DECLARE ARRAY FOR THE GAME BOARD
int carx,cary;
char cartype ;
int goodx,goody;
char board2[30][30] = {
    
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#' },
    { ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', ' ', '#', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#' },
    { '#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#' },
    { '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#', ' ', ' ', '#', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', '#', ' ', '#', '#' },
    { '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', ' ', '#', ' ', '#', '#' },
    { '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '#', '#', '#' },
    { '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#' },
    { ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
    
    
};
char board[30][30]={
    
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ','#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#'},
    {'#','#','#','#','#','#',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#'},
    {'#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#',' ','#','#'},
    {'#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#',' ','#','#'},
    {'#','#','#',' ','#','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ','#','#'},
    {'#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#'},
    {'#','#',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#'},
    {'#','#',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#'},
    {'#','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#'},
    {'#','#',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
    {'#','#',' ',' ','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#'},
    {'#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#'},
    {'#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#'},
    {'#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#',' ','#',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#','#',' ','#','#','#',' ','#',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ','#',' ','#',' ','#'},
    {'#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#'},
    {'#','#','#',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#'},
    {'#','#','#',' ','#',' ','#','#','#',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#'},
    {'#','#','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#',' ','#',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#'},
    {' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
    
};
//function that prints the board
void printboard(){
    system("clear");
    int i;
    int j;
    for(i=0;i<30;i++){
        
        for(j=0;j<30;j++){
            
            cout<<board[i][j];
            
        }
        cout<<"\n";
    }
    
}
//placing bonusses on the board matrix
void bonus(){
    srand(time(NULL)); //We've used <stdlib.h> library and this provides random places for bonuses each time the game runs
    //generating random cordinates for bonnuses
    // collumn and row
    int col = rand() % 29;
    int row = rand() % 29;
    while(board[row][col] != ' '){
        col = rand() % 29;
        row = rand() % 29;
        
    }
    
    board[row][col]='o';
    goodx=col;
    goody=row;
    
    
    col = rand() % 29;
    row = rand() % 29;
    while(board[row][col] != ' '){
        col = rand() % 29;
        row = rand() % 29;
    }
    
    board[row][col]='o';
    carx=col;
    cary=row;
    
    
    col = rand() % 29;
    row = rand() % 29;
    while(board[row][col] != ' '){
        col = rand() % 29;
        row = rand() % 29;
    }
    board[row][col]='o';
}
void changecartype(){
    cartype = '$';
}

void changecartype2(){
    char a=42;
    cartype = a;
}

int timer=60;
int game(){
    //car type
    cartype = '%';
    //initial pozition of car (x=1 , y=1)
    int xpoz=1;
    int ypoz=1;
    
    //creating the of the location car in board
    char *mycar=&board[ypoz][xpoz];
    *mycar=cartype;
    
    char button;
    bonus();
    printboard();
    
    //choosing the playstayle
    int playstyle;
    cout<<"If you want to play by yourself press 1, otherwise let the cpu play for you and press 2"<<endl;
    cin>>playstyle;
    
    time_t start_t, now_t;
    double diff_t;
    
    time(&start_t);
    
    time(&now_t);
    diff_t = difftime(now_t, start_t);
    
    //calculating the score with the time
    
    double score;
    score=1000;
    
    while(board[28][0] != cartype){
        if(diff_t>=timer){
            
            break;
        }
        switch (playstyle)
        {
            case 1 : {
                cout<<"Created by Onur Kaynar and Erhan Biçer"<<endl;
                
                cout<<"USE A FOR LEFT,W FOR UP,S FOR DOWN,D FOR RIGHT BUTTONS TO MOVE YOUR CAR"<<endl;
                cout<<"O ARE THE BONNUSES THAT WILL EFFECT YOUR CAR RANDOMLY"<<endl;
                cin>>button;
                time(&now_t);
                diff_t = difftime(now_t, start_t);
                cout<<"time is:"<<diff_t<<endl;
                
                if(diff_t<=timer){
                    
                    if ((button == 'c') || (button == 'C')) {
                        
                        changecartype2();
                        //Cheat that changes the type of car
                        
                        
                    }
                    
                    else if ((button=='t')||(button=='T')){
                        
                        start_t += 10;                           //Cheat that decreaes passed time
                        
                        
                    }
                    
                    else  if ((button == 'x') || (button == 'X')) {
                        //Cheat that teleports the user
                        if (board[ypoz][xpoz + 1] != '#') {
                            if (board[ypoz][xpoz + 1] == 'o') {
                                if ((ypoz == goody) && (xpoz + 1 == goodx)) { start_t += 10; }
                                else if ((ypoz == cary) && (xpoz + 1 == carx)) { changecartype();
                                    
                                }
                                
                                else { start_t -= 10; }
                            }
                            *mycar = ' ';
                            xpoz = 26;
                            ypoz = 28;
                            mycar = &board[xpoz][ypoz];
                            *mycar = cartype;
                            printboard();
                        }
                    }
                    if(( button == 'a') || (button == 'A')){
                        
                        if(board[ypoz][xpoz-1]!='#'){
                            if(board[ypoz][xpoz-1]=='o'){
                                if((ypoz==goody) && (xpoz-1== goodx)){start_t+=10;}
                                else if ((ypoz==cary)&&(xpoz-1==carx)){changecartype();}
                                else{start_t-=10;}
                            }
                            *mycar=' ';
                            xpoz--;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                        }
                        else if (board[ypoz][xpoz-1]=='#' && board[ypoz][xpoz-2]==' ')
                        {
                            score = score - 20;
                            *mycar=' ';
                            xpoz-=2;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else { printboard();}
                    }
                    else if ((button == 'w')||(button == 'W')){
                        
                        if(board[ypoz-1][xpoz]!='#'){
                            if(board[ypoz-1][xpoz]=='o'){
                                if((ypoz-1==goody) && (xpoz == goodx)){start_t+=10;}
                                else if ((ypoz-1==cary)&&(xpoz==carx)){changecartype();}
                                else{start_t-=10;}
                            }
                            *mycar=' ';
                            ypoz--;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                        }
                        else if (board[ypoz-1][xpoz]=='#' && board[ypoz-2][xpoz]==' ')
                        {
                            score = score - 20;
                            *mycar=' ';
                            ypoz-=2;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else { printboard();}
                    }
                    else if ((button == 's')||(button == 'S')){
                        if(board[ypoz+1][xpoz]!='#'){
                            if(board[ypoz+1][xpoz]=='o'){
                                if((ypoz+1==goody) && (xpoz == goodx)){start_t+=10;}
                                else if ((ypoz+1==cary)&&(xpoz==carx)){changecartype();}
                                else{start_t-=10;}
                            }
                            *mycar=' ';
                            ypoz++;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else if (board[ypoz+1][xpoz]=='#' && board[ypoz+2][xpoz]==' ')
                        {
                            score = score - 20;
                            *mycar=' ';
                            ypoz+=2;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else { printboard();}
                    }
                    else if ((button == 'd')||(button == 'D')){
                        
                        if(board[ypoz][xpoz+1]!='#'){
                            if(board[ypoz][xpoz+1]=='o'){
                                if((ypoz==goody) && (xpoz+1 == goodx)){start_t+=10;}
                                else if ((ypoz==cary)&&(xpoz+1==carx)){changecartype();}
                                else{start_t-=10;}
                            }
                            *mycar=' ';
                            xpoz++;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else if (board[ypoz][xpoz+1]=='#' && board[ypoz][xpoz+2]==' ')
                        {
                            score = score - 20;
                            *mycar=' ';
                            xpoz+=2;
                            mycar=&board[ypoz][xpoz];
                            *mycar=cartype;
                            printboard();
                            
                        }
                        else { printboard();}
                    }
                }
                break;
                
            }
                
            case 2 : {
                
                for(;;) {
                    int direction = rand() % 4;
                    time(&now_t);
                    diff_t = difftime(now_t, start_t);
                    cout<<"time is:"<<diff_t<<endl;
                    
                    if(diff_t<=timer){
                        if(direction == 1){
                            if(board[ypoz][xpoz-1]!='#'){
                                if(board[ypoz][xpoz-1]=='o'){
                                    if((ypoz==goody) && (xpoz-1== goodx)){start_t+=10;}
                                    else if ((ypoz==cary)&&(xpoz-1==carx)){changecartype();}
                                    else{start_t-=10;}
                                }
                                *mycar=' ';
                                xpoz--;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                            }
                            else if (board[ypoz][xpoz-1]=='#' && board[ypoz][xpoz-2]==' ')
                            {
                                score = score - 20;
                                *mycar=' ';
                                xpoz-=2;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else { printboard();}
                        }
                        else if (direction == 2){
                            
                            if(board[ypoz-1][xpoz]!='#'){
                                if(board[ypoz-1][xpoz]=='o'){
                                    if((ypoz-1==goody) && (xpoz == goodx)){start_t+=10;}
                                    else if ((ypoz-1==cary)&&(xpoz==carx)){changecartype();}
                                    else{start_t-=10;}
                                }
                                *mycar=' ';
                                ypoz--;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                            }
                            else if (board[ypoz-1][xpoz]=='#' && board[ypoz-2][xpoz]==' ')
                            {
                                score = score - 20;
                                *mycar=' ';
                                ypoz-=2;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else { printboard();}
                        }
                        else if (direction == 0 ){
                            if(board[ypoz+1][xpoz]!='#'){
                                if(board[ypoz+1][xpoz]=='o'){
                                    if((ypoz+1==goody) && (xpoz == goodx)){start_t+=10;}
                                    else if ((ypoz+1==cary)&&(xpoz==carx)){changecartype();}
                                    else{start_t-=10;}
                                }
                                *mycar=' ';
                                ypoz++;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else if (board[ypoz+1][xpoz]=='#' && board[ypoz+2][xpoz]==' ')
                            {
                                score = score - 20;
                                *mycar=' ';
                                ypoz+=2;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else { printboard();}
                        }
                        else if (direction == 3){
                            
                            if(board[ypoz][xpoz+1]!='#'){
                                if(board[ypoz][xpoz+1]=='o'){
                                    if((ypoz==goody) && (xpoz+1 == goodx)){start_t+=10;}
                                    else if ((ypoz==cary)&&(xpoz+1==carx)){changecartype();}
                                    else{start_t-=10;}
                                }
                                *mycar=' ';
                                xpoz++;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else if (board[ypoz][xpoz+1]=='#' && board[ypoz][xpoz+2]==' ')
                            {
                                score = score - 20;
                                *mycar=' ';
                                xpoz+=2;
                                mycar=&board[ypoz][xpoz];
                                *mycar=cartype;
                                printboard();
                                
                            }
                            else { printboard();}
                        }
                    }
                    
                    
                    break; }
            }
        }
    }
    
    if(diff_t>=timer)
        diff_t=timer;
    score=score-diff_t*10;
    //write the score into a file
    ofstream myfile;
    myfile.open ("highscore.txt");
    myfile << score<<endl;
    myfile.close();
    cout<<score<<"\t"<<"point"<<endl;
    if(board[28][0] == cartype){
        cout<<"You've succesfully finished the maze. Congrats!"<<endl;
        
    }
    else{
        cout<<"GAME OVER"<<endl;
    }
    
    
    
    
    
    
    
    return 0;
    
}
int main(int argc, const char * argv[]) {
    int i,j;
    
    game();
    if(board[28][0] == cartype){
        for(i=0;i<30;i++){
            for (j=0;j<30;j++){
                
                board[i][j]=board2[i][j];
            }
        }
        
        game();
    }
    
    
    
    
    
    
    return 0;
}
