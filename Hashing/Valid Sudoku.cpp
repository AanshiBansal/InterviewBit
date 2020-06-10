//The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
int Solution::isValidSudoku(const vector<string> &A) {
    for(int i=0;i<9;i++){
        vector<bool>mp(10,false);
        for(int j=0;j<9;j++){
            int num=A[i][j]-'0';
            if(num>=1 && num<=9){
                if(mp[num])
                return 0;
                mp[num]=true;
            }
        }
    }
    for(int i=0;i<9;i++){
        vector<bool>mp(10,false);
        for(int j=0;j<9;j++){
            int num=A[j][i]-'0';
            if(num>=1 && num<=9){
                if(mp[num])
                return 0;
                mp[num]=true;
            }
        }
    }
    for(int i=0;i<9;i=i+3){
        for(int j=0;j<9;j=j+3){
            vector<bool>mp(10,false);
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    int num=A[i+k][j+l]-'0';
                    if(num>=1 && num<=9){
                        if(mp[num])
                        return 0;
                        mp[num]=true;
                    }
                }
            }
        }
    }
    return 1;
}
