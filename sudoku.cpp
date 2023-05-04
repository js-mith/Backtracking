#include<bits/stdc++.h>
using namespace std;
#define N 9

bool findemptylocation(int grid[N][N] , int &row , int &col){
    for(int i =0 ; i < N ; i++){
        for(int j=0 ; j<N ; j++){
            if(grid[i][j] == 0){
                row = i;
                col =j;
                return true;
            }
        }
    }
    return false;
}

bool issafeinrow(int grid[N][N] , int row , int num){
    for(int i =0 ; i < N ; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool issafeincol(int grid[N][N] , int col , int num){
    for(int i =0 ; i < N ; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool issafeingrid(int grid[N][N] , int row ,int col , int num){
    int rowfactor = row - (row%3);
    int colfactor = col - (col%3);
    for(int i =0 ; i < 3 ; i++){
        for(int j =0 ; j < 3 ; j++){
            if(grid[i+rowfactor][j+colfactor] == num){
                return false;
            }
        }
    }
    return true;
}

bool issafe(int grid[N][N], int row ,int col , int num){
    if(issafeinrow(grid,row,num) && issafeincol(grid , col , num) && issafeingrid(grid , row , col , num)){
        return true;
    }
    return false;
}

bool solvesudoku(int grid[N][N]){
    int row,col;
    if(!findemptylocation(grid,row,col)){
        return true;
    }
    for(int i =1 ; i <= N ; i++){
        if(issafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solvesudoku(grid)){
                return true;
            }
            grid[row][col]= 0;
        }
    }
    return false;
}
int main(){

    int grid[N][N];
    for(int i =0 ; i < N ; i++){
        string s;
        cin>>s;
        for(int j =0 ; j<s.length() ; j++){
             grid[i][j] = s[j] - '0';
        }
    }

    solvesudoku(grid);

    cout << "======ANS====" << endl;
    for(int i =0 ; i < N ; i++){
        for(int j =0 ; j < N ; j++){

            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}