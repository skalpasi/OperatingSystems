#include <fcntl.h>
#include <unistd.h>

int main() {
  char buf1[] = "abcdefghij"; // 10 bytes buffer
  char buf2[] = "ABCDEFGHIJ"; // 10 bytes buffer
  int fd = creat("file.hole", S_IRUSR | S_IRWXG | S_IWUSR);
  write(fd, buf1, 10);
  lseek(fd, 1000, SEEK_SET); // set the offset to 1000 bytes from starting
  // this will create a hole (\0) of 990 bytes
  write(fd, buf2, 10);

  /* this will create a file with first 10 bytes as buf1 and then
   a sequence of 990 null byte characters (hole) and then another
   10 bytes of buf2 */
  // use "xxd file.hole" to check it out
}
