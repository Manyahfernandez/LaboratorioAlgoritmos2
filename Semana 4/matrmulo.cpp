/*
* Se busca implementar el metodo de strassen para multiplicar matrices cambiando por vectores las matrices ya que no supe uint32_t y uint64_t 
*/

#include<iostream>
#include <vector>
using namespace std;

vector<vector<unsigned long>> restarMatrices(vector<vector<unsigned long>> &A, vector<vector<unsigned long>> &B){
    int n = A.size();
    vector<vector<unsigned long>> C(n, vector<unsigned long>(n, 0));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<unsigned long>> sumarMatrices(vector<vector<unsigned long>> &A, vector<vector<unsigned long>> &B){
    int n = A.size();
    vector<vector<unsigned long>> C(n, vector<unsigned long>(n, 0));
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<unsigned long>> strassen(vector<vector<unsigned long>> &A, vector<vector<unsigned long>> &B){
    int n = A.size();
    vector<vector<unsigned long>> C(n, vector<unsigned long>(n, 0));
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
    }
    else{

        int m = n/2;
        vector<vector<unsigned long>> A11(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> A12(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> A21(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> A22(m, vector<unsigned long>(m));
        
        vector<vector<unsigned long>> B11(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> B12(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> B21(m, vector<unsigned long>(m));
        vector<vector<unsigned long>> B22(m, vector<unsigned long>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + m];
                A21[i][j] = A[i + m][j];
                A22[i][j] = A[i + m][j + m];
                
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + m];
                B21[i][j] = B[i + m][j];
                B22[i][j] = B[i + m][j + m];
            }
        }

        vector<vector<unsigned long>> RB12B22 = restarMatrices(B12, B22);
        vector<vector<unsigned long>> SA11A12 = sumarMatrices(A11, A12);
        vector<vector<unsigned long>> SA21A22 = sumarMatrices(A21, A22);
        vector<vector <unsigned long>> RB21B11 = restarMatrices(B21, B11);
        vector<vector<unsigned long>> SA11A22 = sumarMatrices(A11, A22), SB11B22 = sumarMatrices(B11, B22);
        vector<vector<unsigned long>> RA12A22 = restarMatrices(A12, A22), SB21B22 = sumarMatrices(B21, B22);
        vector<vector<unsigned long>> RA11A21 = restarMatrices(A11, A21), SB11B12 = sumarMatrices(B11, B12);

        vector<vector<unsigned long>> P1 = strassen(A11, RB12B22);
        vector<vector<unsigned long>> P2 = strassen(SA11A12, B22);
        vector<vector<unsigned long>> P3 = strassen(SA21A22, B11);
        vector<vector<unsigned long>> P4 = strassen(A22, RB21B11);
        vector<vector<unsigned long>> P5 = strassen(SA11A22, SB11B22);
        vector<vector<unsigned long>> P6 = strassen(RA12A22, SB21B22);
        vector<vector<unsigned long>> P7 = strassen(RA11A21, SB11B12);

        vector<vector<unsigned long>> P5P4 = sumarMatrices(P5, P4);
        vector<vector<unsigned long>> P5P4P2 = restarMatrices(P5P4, P2);
        vector<vector<unsigned long>> P1P5 = sumarMatrices(P1, P5);
        vector<vector<unsigned long>> P1P5P3 = restarMatrices(P1P5, P3);

        vector<vector<unsigned long>> C11 = sumarMatrices(P5P4P2, P6);
        vector<vector<unsigned long>> C12 = sumarMatrices(P1, P2);
        vector<vector<unsigned long>> C21 = sumarMatrices(P3, P4);
        vector<vector<unsigned long>> C22 = restarMatrices(P1P5P3, P7);


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                C[i][j] = C11[i][j];
                C[i][j + m] = C12[i][j];
                C[i + m][j] = C21[i][j];
                C[i + m][j + m] = C22[i][j];
            }
        }
    }  

    return C; 
}

int main(){
    unsigned long n,i,j,d1,r1,m1,d2,p2,m2,r2,p1;

    //here you need to read n, p1, d1, r1, m1, p2, d2, r2, m2 from input.

    cin >> n;
    cin >> p1 >> d1 >> r1 >> m1;
    cin >> p2 >> d2 >> r2 >> m2;

    vector<vector<unsigned long>> A(n, vector<unsigned long>(n,0)), B(n, vector<unsigned long>(n,0)), C(n, vector<unsigned long>(n,0));
    vector<unsigned long> V(n,0);

    for (i=0; i<n; ++i){
        for (j=0; j<n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }
    }

    C = strassen(A,B);

    //here you need to calculate C=A*B
    for (i=0; i<n; ++i) {
        V[i] = 0;
        for (j=0; j<n; ++j){
            V[i] ^= C[i][j];
        }
    }
    //here you need to output V[0], V[1], ..., V[n-1], separated by spaces.

    for(i = 0; i < n; i++){
        cout<< V[i] <<" ";
    }

}