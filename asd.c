#include "include/shellft.h"
#include <stdio.h>

int main(int a, char **b)
{
	t_cmdsub *pt = _cmdsub_parse(b[1]);
	while (pt)
	{
		printf("bgn = %s\nend = %s\n\nerrno = %d\npt_err = %s\n\nqt.bgn = %s\nqt.end = %s\n\nnext = %p\n", pt->bgn, pt->end, pt->errno, pt->pt_err, pt->qt.bgn, pt->qt.end, pt->next);
		pt = pt->next;
	}
}
