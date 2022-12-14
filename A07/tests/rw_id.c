#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>

int	main(void)
{
	char	buf[10];
	int	fd;
	int	ret;

	bzero(buf, 10);	
	fd = open("/sys/kernel/debug/fourtytwo/id", O_RDWR);
	if (fd > 0)
	{
		printf("\n___ ID ___\n");
		ret = read(fd, buf, 10);
		printf("1st read [%s] ret : %d\n", buf, ret);
		ret = read(fd, buf, 10);
		printf("2st read [%s] ret : %d\n", buf, ret);
		ret = write(fd, "tmeyer", 6);
		printf("1st write (tmeyer, 6) ret : %d\n", ret);
		ret = write(fd, "abcd", 4);
		printf("2st write (abcd, 4) ret : %d\n", ret);
		ret = write(fd, "abcdefgh", 20);
		printf("3st write (abcdefgh, 20) ret : %d\n", ret);
		close(fd);
	}
	else
		dprintf(2, "No such file id\n");

	return (0);
}
