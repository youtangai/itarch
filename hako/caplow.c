#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/file.h>
#define CHAR_SIZE 1
#define BUFF_SIZE 8

char change_up_low(char c) {
		if (isupper(c)) {
				//this is upper case
				return tolower(c);
		} else {
				//this is lower case
				return toupper(c);
		}
}

int main(int argc, char *argv[])
{
		int fd_dev, count;
		char buff[CHAR_SIZE+1];
		char disp[BUFF_SIZE+1];

		//check args
		if (argc < 3) {
				printf("Usage %s devfilename(absolute) count\n", argv[0]);
				return -1;
		}

		//open the devicefile read/write mode
		fd_dev = open(argv[1], O_RDWR);
		if (fd_dev < 0) {
				perror(argv[1]);
				return -1;
		}

		count = atoi(argv[2]);


		if (count == 0){
				read(fd_dev, disp, 8);
				disp[BUFF_SIZE] = '\0';
				printf("%s\n", disp);
				return 0;
		}

		for (int i = 0; i < count; i++) {
				//flock(fd_dev, LOCK_EX);
				read(fd_dev, buff, CHAR_SIZE);
				buff[CHAR_SIZE] = '\0';

				//todo cap to small function
				buff[0] = change_up_low(buff[0]);
				//printf("%s\n", buff);

				write(fd_dev, buff, CHAR_SIZE);
				//flock(fd_dev, LOCK_UN);
		}
		close(fd_dev);

		return 0;
}
