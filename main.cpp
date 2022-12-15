#include <curses.h>
#include <stdlib.h>
#include <sys/random.h>


int main(void)
{
	int index;
	int maxlines, maxcols;

	/*initialize curses */
	initscr();
	cbreak();
	noecho();

	clear();

/* initialize graph */

	maxlines = LINES -1;
	maxcols = COLS -1;





/* End */
	mvaddstr(maxlines, 0, "Press any key to quit!");
	refresh();
	getch();
	endwin();
	exit(0);

}
