#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = open("./fcntl", O_RDWR | O_CREAT | O_NONBLOCK, 0644);

  // 1. duplicate and print new fd
  printf("%d\n", fcntl(fd, F_DUPFD, 2));

  int statusFlag = fcntl(fd, F_GETFL);
  // 2. get file access status
  printf("%d\n", statusFlag & O_ACCMODE);  // O_ACCMODE = 3
  printf("%d\n", statusFlag & O_APPEND);   // 1024 if enabled else 0
  printf("%d\n", statusFlag & O_NONBLOCK); // 2048 if enabled else 0

  /* mask the value of statusFlag with the constants to get the status of each
   * constant

    O_APPEND -> 1024
    O_NONBLOCK -> 2048
   */

  /* update file status flags
     fetch status flag -> modify it -> set status flag */
  printf("%d\n", statusFlag);
  statusFlag = statusFlag | O_APPEND; // append flag is set in status flag
  fcntl(fd, F_SETFL, statusFlag);
  printf("%d\n", statusFlag & O_APPEND); // 1024 cuz append is on now

  // for clearing status flags: statusFlag &= ~flag

  return 0;
}
