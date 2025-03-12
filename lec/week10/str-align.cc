#include <iostream>
using namespace std;

int score(char a,char b){
    return (a == b ? 2 : -1);
}
int max(int a,int b){
    return (a > b ? a : b);
}
void align(string &s1,string &s2){
    int VR = s1.length()+1;
    int VC = s2.length()+1;
    int V[VR][VC];

    for(int i = 0;i < VR;++i){
        for(int j = 0;j< VC;++j){
            if(!i && !j){
                V[i][j] = 0; //no score match 2-empty string
            }else if(i == 0 && j){
                V[i][j] = j * score(0,s2[j-1]); //delete sub-string A[i...]
            }else if (j == 0 && i){
                V[i][j] = i * score(0,s1[i-1]); //insert spaces B[j...] 
            }else{
                int o1,o2,o3;
                o1 = V[i-1][j-1] + score(s1[i-1],s2[j-1]); //score match Ai,Bj
                o2 = V[i-1][j] + score(s1[i-1],0); //delete Ai
                o3 = V[i][j-1] + score(0,s2[j-1]);  //insert Bj
                V[i][j] = max(o1,max(o2,o3));
            }
            cout << V[i][j] << " ";

        }
        cout << endl;
    }




}

int main(){
    string A = "ACAATCC";
    string B = "AGCATGC";


    align(A,B);


    return 0;   
}