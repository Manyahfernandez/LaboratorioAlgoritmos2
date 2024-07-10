
/*
* Se dio de cuenta que inicialmente la matrix A debe estar conformada por 1, luego visuzalizar en que valores 
*la matriz B es 0 pues en este caso todos los valores que conforman ese elemento seran 0
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int m, n;

	cin >> m >> n;

	vector<vector<int>> matrix(m,vector<int>(n)), matrixA(m,vector<int>(n,1)), matrixVer(m,vector<int>(n));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> matrix[i][j];
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 0){
				for(int k = 0; k < n; k++){
					matrixA[i][k] = 0;
				}

				for(int k = 0; k < m; k++){
					matrixA[k][j] = 0;
				}
			}
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int col = 0;
			for(int k = 0; k < n; k++){
				col = col || matrixA[i][k];
			}

			int row = 0;
			for(int k = 0; k < m; k++){
				col = col || matrixA[k][j];
			}

			if(matrix[i][j] != (col || row)){
				cout << "NO"<<"\n";
				return 0;
			}
		}
	}

	cout<<"YES"<<"\n";
	for(int i = 0; i < m; i ++){
		for(int j = 0; j < n; j++){
			cout <<matrixA[i][j]<<" ";
		}
		cout<<"\n";
	}



	return 0;
}