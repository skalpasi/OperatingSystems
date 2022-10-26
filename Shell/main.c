#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "$ "

char *dynamic_input() {
  int buff_size = 50;
  char *input = (char *)malloc(buff_size);

  char c = EOF;
  int count = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    input[count++] = c;
    if (count == buff_size) {
      printf("reallocating memory");
      input = realloc(input, buff_size * 2);
    }
    input[count] = '\0';
  }

  char *final_input = input;
  free(input);
  printf("<%p><%p>", &final_input, &input);
  return final_input;
}

int main(int argc, char **argv) {
  int STATUS_CODE;
  // main loop
  while (1) {
    printf("%s ", PROMPT);
    char *command = dynamic_input();
    // printf("%s", command);
  }

  return STATUS_CODE;
}
