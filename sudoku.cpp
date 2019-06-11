#include<bits/stdc++.h>

#define for0(i,n) for(int i = 0;i < n;i++)
#define for1(i,n) for(int i = 1;i<=n;i++)

using namespace std;

int col[9][10] = {{0}},row[9][10] = {{0}},cell[9][10] = {{0}},sudo[9][9] = {{0}};

int cellno(int r,int c){
    return (int)(r/3)*3 + c/3;
}

void print_sol() {
    for0(i,9){
        if(i%3 == 0 && i) cout<<" ";
        cout<<" _____";
    }
    cout<<"\n";
    for0(i,9){
        if(i%3 == 0 && i){
            for0(j,9){
               if(j%3 == 0 && j) cout<<" ";
               cout<<" _____";
            }
            cout<<"\n";
        }
        for0(k,3){
            for0(j,9){
                if(j%3 == 0 && j != 0) cout<<"|";
                if(k == 0) cout<<"|     ";
                else if(k == 1) cout<<"|  "<<sudo[i][j]<<"  ";
                else cout<<"|_____";
            }
            cout<<"|\n";
        }
    }
}

bool soln(int r,int c) {
    if(r == 9){
        print_sol();
        return true;
    }
    else if(c == 9){
        return soln(r+1,0);
    }
    if(sudo[r][c] != 0) return soln(r,c+1);
    for1(n,9){
        if(!row[r][n] && !col[c][n] && !cell[cellno(r,c)][n]){
            row[r][n] = 1;
            col[c][n] = 1;
            cell[cellno(r,c)][n] = 1;
            sudo[r][c] = n;
            bool res = soln(r,c+1);
            if(res) return true;
            row[r][n] = col[c][n] = cell[cellno(r,c)][n] = 0;
            sudo[r][c] = 0;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../cp/input.txt","r",stdin);
    freopen("../cp/output.txt","w",stdout);
    #endif
    for0(i,9){
        for0(j,9){
            char tmp;
            cin>>tmp;
            if(isdigit(tmp)) {
                sudo[i][j] = tmp-'0';
                row[i][sudo[i][j]] = 1;
                col[j][sudo[i][j]] = 1;
                cell[cellno(i,j)][sudo[i][j]] = 1;
            }
        }
    }
    if(!soln(0,0)) {
        cout<<"NO SOLUTION SEEM TO EXIST\n";
    }
}
