#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int		main(int ac, char **av)
{
	struct stat statf;
	lstat(av[1], &statf);

	printf("%lld\n", statf.st_mtim);
}
