#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <unistd.h>
#include <cmath>

using namespace std;


int main()
{
    initscr;
    noecho;
    int max_x, max_y; 
    getmaxyx(stdscr, max_y, max_x);
    int mid_y = (max_y/2);
    int mid_x = (max_x/2);
    int y_pos;
    int x_pos;
    int wave_height;
    int wave_length;
    int wave_amplitude; 
    int wave_frequency;
    int wave_speed;
    int wave_direction;
    int wave_cycle;
    int wave_offset;

    wave_length = (max_x/4)+1;
    wave_amplitude = max_y/2;
    wave_frequency = 6;
    wave_speed = 1;
    wave_direction = 1;
    wave_offset = 0;

    while(1)
    {
        for(int i=0; i<= wave_length; i++)
        {
            wave_height = wave_amplitude * sin(wave_frequency * i + wave_offset);
            y_pos = mid_y + wave_height;
            x_pos = mid_x + wave_direction * i;
            mvaddch(y_pos, x_pos, '#');
            wave_offset += wave_speed;
            refresh();
            usleep(100000);
        }
    }

    endwin();

    return 0;

}
