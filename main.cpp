
#include <iostream>
#include <stdlib.h>

using namespace std;



template<typename T, size_t N, size_t M>
void printArray(T(&mat)[N][M])
{
	for (int i = 0; i < N; i ++ ) {
		for (int j = 0; j < M; j++ ) {
			cout << mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
 
int main()
{
	const int m = 80, n = 80;
 
	int mat[m][n] = {

	};
 
	printArray(mat);
 
	return 0;
}
