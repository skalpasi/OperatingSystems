#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = open("./file", O_RDWR);
  int fd1 = dup(fd);
  char buf[12];
  read(fd, buf, 12);
  write(fd1, buf, 12);
  printf("%d %d\n", fd, fd1);
}
