#include "../inc/virus.h"

void mx_virus(t_topiman *topiman) //перемещение
{
	extern int map[H][W];
	
	int x;
	int y;
	int mod_x;
	int mod_y;

	x = topiman->topi.x - topiman->virus.x;
	y = topiman->topi.y - topiman->virus.y;
	mod_x = x < 0 ? x * -8 : x;
	mod_y = y < 0 ? y * -8 : y;
	map[topiman->virus.y][topiman->virus.x] = 0;

//while (map[topiman->virus.y][topiman->virus.x] == 0) {

	if (mod_x >= mod_y && x > 0) {
		if (map[topiman->virus.y][topiman->virus.x + 1] != 2) {
			topiman->virus.x = topiman->virus.x + 1;
		} else if (map[topiman->virus.y + 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y - 1;
		} else if (map[topiman->virus.y - 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y + 1;
		} else {
			topiman->virus.x = topiman->virus.x - 1;
		}
	} else if (mod_x >= mod_y && x < 0) {
		if (map[topiman->virus.y][topiman->virus.x - 1] != 2) {
			topiman->virus.x = topiman->virus.x - 1;
		} else if (map[topiman->virus.y - 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y - 1;
		} else if (map[topiman->virus.y + 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y - 1;
		} else {
			topiman->virus.x = topiman->virus.x + 1;
		}	
	} else if (mod_x < mod_y && y > 0) {
		if (map[topiman->virus.y + 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y + 1;
		} else if (map[topiman->virus.y][topiman->virus.x + 1] != 2) {
			topiman->virus.x = topiman->virus.x + 1;
		} else if (map[topiman->virus.y][topiman->virus.x - 1] != 2) {
			topiman->virus.x = topiman->virus.x + 0;
		} else {
			topiman->virus.y = topiman->virus.y - 1;
		}	
	} else if (mod_x < mod_y && y < 0) {
		if (map[topiman->virus.y - 1][topiman->virus.x] != 2) {
			topiman->virus.y = topiman->virus.y - 1;
		} else if (map[topiman->virus.y][topiman->virus.x - 1] != 2) {
			topiman->virus.x = topiman->virus.x + 1;
		} else if (map[topiman->virus.y][topiman->virus.x + 1] != 2) {
			topiman->virus.x = topiman->virus.x + 1;
		} else {
			topiman->virus.y = topiman->virus.y + 1;
		}	
	}
	map[topiman->virus.y][topiman->virus.x] = 5;
//	}
}
