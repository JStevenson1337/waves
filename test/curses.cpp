<<<<<<< HEAD
#include <curses.h>
#include <stdlib.h>
#include <sys/random.h>


#define ITERMAX 10000


int main(void)
{
	long iter;
  int yi, xi;
  int y[3], x[3];
  int index;
  int maxlines, maxcols;

  /* initialize curses */

  initscr();
  cbreak();
  noecho();

  clear();
  
  /* initialize triangle */

  maxlines = LINES -1;
  maxcols = COLS -1;

  y[0] = 0;
  x[0] = 0;

  y[1] = maxlines;
  x[1] = maxcols / 2;

  y[2] = 0;
  x[2] = maxcols;

  mvaddch(y[0], x[0], '0');
  mvaddch(y[1], x[0], '0');
  mvaddch(y[2],x[2], '2');

  /* initialize yi, xi with random value */
   yi = random() % maxlines;
   xi = random() % maxcols;

   mvaddch(yi, xi, '.');

   /* ierate the triangle */

   for (iter = 0; iter < ITERMAX; iter++)
      {

       index = random() % 3;
       yi = (yi + y[index]) / 2;
       xi = (xi + x[index]) / 2;

       mvaddch(yi, xi, '*');
       refresh();
       }
  /* done */

       mvaddstr(maxlines, 0, "Press any key to quit");

    refresh();
    getch();
    endwin();

    exit(0);

=======

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
>>>>>>> fcbe12dcd1109367b780107bd44cb8ff6bc3f15b
}

