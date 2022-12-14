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
   while (1)
   {
      for (iter = 0; iter < ITERMAX; iter++)
         {

          index = random() % 3;
          yi = (yi + y[index]) / 2;
          xi = (xi + x[index]) / 2;

          mvaddch(yi, xi, '*');
          refresh();
          }
          
   }
  /* done */

       mvaddstr(maxlines, 0, "Press any key to quit");

    refresh();
    getch();
    endwin();

    exit(0);

}

