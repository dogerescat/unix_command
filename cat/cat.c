#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	u_int8_t buf[4096];
	ssize_t nread;
	int fd = STDIN_FILENO;
	if(argc > 1) {
		fd = open(argv[1], O_RDONLY);
		if(fd < 0) {
			fprintf(stderr, "cannot open %s\n", argv[1]);
			exit(1);
		}	
	}	
	while((nread = read(0, buf, sizeof(buf))) > 0) {
		write(1, buf, nread);
	}
	return 0;
}
