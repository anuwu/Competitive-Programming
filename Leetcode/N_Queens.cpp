class Solution {
public:
    void print_board(vector<string> &board)
    {
        int n = board.size() ;
        for (int i = n-1 ; i >= 0 ; i--)
            cout << board[i] << "\n" ;
    }
    
    bool isvalid(int row, int col, vector<string> board)
    {
        if (row == 0)
            return true ;
        
        int disp ;
        for (int r=0 ; r<row ; r++)
        {
            if (board[r][col] == 'Q')
                return false ;
            
            disp = row - r ;
            if (col - disp >= 0 && board[r][col-disp] == 'Q' || col + disp < board.size() && board[r][col+disp] == 'Q')
                return false ;
            
        }
        
        return true ;
    }
    
    void fill_row(int row, vector<string> board, vector<vector<string>> &vv)
    {        
        int n = board.size() ;
        for (int col = 0 ; col < n ; col++)
        {
            if (isvalid(row, col, board))
            {
                board[row][col] = 'Q' ;
                // board[row].replace(col, 1, "Q") ;
               
                if (row == n-1)
                    vv.push_back(board) ;
                else
                    fill_row(row+1, board, vv) ;

                board[row][col] = '.' ;
                // board[row].replace(col, 1, ".") ;
            }
        }
    }
                
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> vv ;
        
        if (n < 4)
        {            
            if (n == 1)
            {
                vector<string> v ;
                v.push_back("Q") ;
                vv.push_back(v) ;
            }
            
            return vv ;
        }
            
        vector<string> blank ;
        for (int i = 0 ; i < n ; i++)
        {
            string str (n, '.') ;
            blank.push_back(str) ;
        }
        
        fill_row(0, blank, vv) ;
        return vv ;
    }
};
