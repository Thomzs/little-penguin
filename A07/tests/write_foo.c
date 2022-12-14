#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <errno.h>

#define PAGE_SIZE 4096

int	main(void)
{
	int	fd;
	int	ret;
	char	buf[PAGE_SIZE];

	fd = open("/sys/kernel/debug/fourtytwo/foo", O_RDWR);
	memset(buf, 'A', PAGE_SIZE);
	if (fd > 0)
	{
		ret = write(fd, buf, PAGE_SIZE - 1);
		if (ret == -1)
		{
			perror("error");
		}
		printf("1st write ret %d\n", ret);
		close(fd);
	}
	else
		dprintf(2, "No such file foo\n");
	
	return (0);
}
