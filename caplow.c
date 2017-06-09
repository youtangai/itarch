#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
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
		char buff[BUFF_SIZE+1];

		//check args
		if (argc < 4) {
				printf("Usage %s devfilename(absollute) index count\n", argv[0]);
				return -1;
		}

		//open the devicefile read/write mode
		fd_dev = open(argv[1], O_RDWR);
		if (fd_dev < 0) {
				perror(argv[1]);
				return -1;
		}

		count = atoi(argv[3]);


		if (count == 0){
				read(fd_dev, buff, BUFF_SIZE);
				buff[BUFF_SIZE] = '\0';
				printf("%s\n", buff);
				return 0;
		}

		int index = atoi(argv[2]);

		for (int i = 0; i < count; i++) {
				read(fd_dev, buff, BUFF_SIZE);
				buff[BUFF_SIZE] = '\0';

				//todo cap to small function
				buff[index] = change_up_low(buff[index]);
				//printf("%s\n", buff);

				write(fd_dev, buff, BUFF_SIZE);
		}

		close(fd_dev);

		return 0;
}
