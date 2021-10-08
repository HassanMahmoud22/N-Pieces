#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;
class Game
{
protected:

    void printSolution(vector<vector<int>> &board,int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    virtual bool isPossible(vector<vector<int>> &board, int row, int col,int n) = 0;

    bool solver(vector<vector<int>> &board, int row,int n)
    {
        if(row >= n)
            return true;
        for(int i = 0; i < n; i++)
        {
            if(isPossible(board, row, i,n))
            {
                board[row][i] = 1;
                if(solver(board, row + 1,n))
                    return true;
                board[row][i] = 0;
            }
        }
        return false;
    }
public:
    void solve()
    {
        cout<<"Enter the dimensions: "<<endl;
        int n;
        cin>>n;
        vector<vector<int>> board;
        for(int i = 0; i < n; i++)
        {
            board.push_back(vector<int>());
            for(int j = 0; j < n; j++)
            {
                board[i].push_back(0);
            }
        }
        if(solver(board, 0, n) == false)
        {
            cout << "Solution does not exist" << endl;
        }
        printSolution(board,n);
    }
};
class Queens: public Game
{
private:

    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        int i, j;
        for (i = 0; i < row; i++)
            if(board[i][col])
                return false;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j])
                return false;
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
            if (board[i][j])
                return false;
        return true;
    }


};

class Soldiers: public Game
{
private:

    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        if(row == 0)
            return true;
        if(row > 1)
            if(board[row-2][col])
                return false;
        if(board[row-1][col])
            return false;
        if(board[row-1][col-1])
            return false;
        return true;
    }
};

class Knights: public Game
{
private:
    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        if(row == 0)
            return true;
        if(row > 1 && col >= 1)
            if(board[row-2][col-1])
                return false;
        if(row >= 1 && col > 1)
            if(board[row-1][col-2])
                return false;
        return true;
    }
};

class Bishops: public Game
{
private:
    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        int i, j;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j])
                return false;
        for (i = row, j = col; j >= 0 && i < n; i++, j--)
            if (board[i][j])
                return false;
        return true;
    }
};

class Rooks: public Game
{
private:

    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        int i, j;
        for (i = 0; i < row; i++)
            if(board[i][col])
                return false;
        return true;
    }

};

class Kings: public Game
{
private:

    bool isPossible(vector<vector<int>> &board, int row, int col,int n)
    {
        if(row == 0)
            return true;
        if(board[row-1][col])
            return false;
        if(board[row-1][col-1])
            return false;
        if (board[row-1][col+1])
            return false;
        return true;
    }

};
void menu()
{
    int choice;
    while(true)
    {
        cout << "choose what you want to apply" << endl;
        cout << "1- n Soldiers" << endl;
        cout << "2- n Bishops" << endl;
        cout << "3- n Rooks" << endl;
        cout << "4- n Knights" << endl;
        cout << "5- n Queens" << endl;
        cout << "6- n Kings" << endl;
        cout << "7- Exit" << endl;
        cin >> choice;
        if( choice > 6 || choice < 1)
            menu();
        if(choice == 1)
        {
            Soldiers obj;
            obj.solve();
        }
        else if(choice == 2)
        {
            Bishops obj;
            obj.solve();
        }
        else if(choice == 3)
        {
            Rooks obj;
            obj.solve();
        }
        else if(choice == 4)
        {
            Knights obj;
            obj.solve();
        }
        else if(choice == 5)
        {
            Queens obj;
            obj.solve();
        }
        else if(choice == 6)
        {
            Kings obj;
            obj.solve();
        }
        else
            exit(0);

    }
}

int main()
{
    menu();
}
