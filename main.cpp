#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Game{
private:
    vector<vector<char>> grid = vector<vector<char>>(3, vector<char>(3, '.'));
    int maxMoves = 9;

public:
    string name1;
    string name2;
    Game(string name1 , string name2){
        this->name1 = name1;
        this->name2 = name2;
    }

    Game(){
        name1 = "player1";
        name2 = "player2";
    }

    void printGrid(){
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void printNames(){
        cout << name1 << endl;
        cout << name2 << endl;
    }

    bool iswon(vector<vector<char>>& grid , int pos){
        int row = pos/3;
        int col = pos%3;

        if(grid[row][0] == grid[row][1] && grid[row][0] == grid[row][2]) return true;
        else if(grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]) return true;
        if(row == col){
            if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) return true;
        }
        else if(row+col == 2){
            if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return true;
        }

        return false;
    }

    void play(){
        int p;
        cout << "Who are making the first move (1 or 2): ";
        cin >> p;

        int moves = 0;
        while(moves < maxMoves){

            if(moves%2 == (p-1)%2) cout << "Time for " << name1 << " to make move!!" << endl;
            else cout << "Time for " << name2 << " to make move!!" << endl;

            printGrid();
            int row , col;
            cout << "Enter the row number : ";
            cin >> row;
            while(row <= 0 || row > 3){
                cout << "Please enter the valid input : ";
                cin >> row;
            }

            cout << "Enter the column Number : ";
            cin >> col;
            while(col <= 0 || col > 3){
                cout << "Please enter the valid input : ";
                cin >> col;
            }

            while(grid[row-1][col-1] != '.'){
                cout << "Please enter the valid input : " << endl;

                cout << "Enter the row number : ";
                cin >> row;

                cout << "Enter the column number : ";
                cin >> col;
            }

            if(moves%2 == 1) grid[row-1][col-1] = 'O';
            else grid[row-1][col-1] = 'X';

            if(iswon(grid , (row-1)*3 + col-1)){
                if(moves%2 == (p-1)%2) cout << name1 << " won the game!";
                else cout << name2 << " won the game!";
                break;
            }

            moves++;
        }
        if(moves == maxMoves) cout << "Nobody won the game.";
    }
};

int main(){
    Game g("Nithish" , "Mahathi");
    g.play();
    return 0;
}