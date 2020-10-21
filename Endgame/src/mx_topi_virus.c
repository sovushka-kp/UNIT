#include "../inc/virus.h"

int mx_topi_virus(t_topiman *topi) {
  if (topi->topi.x == topi->virus.x && topi->topi.y == topi->virus.y) {
	mx_finish_game(topi);
	return 1;
  }
  return 0;
}
