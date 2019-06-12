#include<bits/stdc++.h>

#define for0(i,n) for(int i = 0;i < n;i++)
#define for1(i,n) for(int i = 1;i<=n;i++)

using namespace std;

vector<vector<int> > col,row,cell,sudo;
int N,M;

int cellno(int r,int c){
    return (int)(r/M)*M + c/M;
}

void print_sol() {
    for0(i,N){
        if(i%M == 0 && i) cout<<" ";
        cout<<" _____";
    }
    cout<<"\n";
    for0(i,N){
        if(i%M == 0 && i){
            for0(j,N){
               if(j%M == 0 && j) cout<<" ";
               cout<<" _____";
            }
            cout<<"\n";
        }
        for0(k,3){
            for0(j,N){
                if(j%M == 0 && j != 0) cout<<"|";
                if(k == 0) cout<<"|     ";
                else if(k == 1) cout<<"|  "<<sudo[i][j]<<"  ";
                else cout<<"|_____";
            }
            cout<<"|\n";
        }
    }
}

bool soln(int r,int c) {
    if(r == N){
        print_sol();
        return true;
    }
    else if(c == N){
        return soln(r+1,0);
    }
    if(sudo[r][c] != 0) return soln(r,c+1);
    for1(n,N){
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
    cout<<"Enter the value of N for the N^2 x N^2 sudoku : ";
    cin>>M;
    N = M*M;
    system("cls");
    cout<<endl;
    row.resize(N,vector<int>(N+1,0));
    cell.resize(N,vector<int>(N+1,0));
    sudo.resize(N,vector<int>(N+1,0));
    col.resize(N,vector<int>(N+1,0));
    for0(i,N){
        for0(j,N){
            string tmp;
            cin>>tmp;
            int check = 1;
            for0(i,tmp.length()){
                check &= isdigit(tmp[i]);
            }
            if(check) {
                int no = atoi(tmp.c_str());
                if(no){
                    sudo[i][j] = no;
                    row[i][sudo[i][j]] = 1;
                    col[j][sudo[i][j]] = 1;
                    cell[cellno(i,j)][sudo[i][j]] = 1;
                }
            }
        }
    }
    if(!soln(0,0)) {
        cout<<"NO SOLUTION SEEM TO EXIST\n";
    }
}
