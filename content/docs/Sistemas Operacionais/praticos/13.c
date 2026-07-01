#include <stdio.h>
#include <string.h>
#include <unistd.h>

int parse_string_to_int(char *str) {
  int size = 0;
  int length = strlen(str);
  for (int i = 0, j = length - 1; i < length; i++, j--) {
    size = size * 10 + (str[i] - '0');
  }
  return size;
}

int main(int argc, char *argv[]) {
  int size;

  if (argc > 1) {
    char *mb = argv[1];
    printf("%s\n", mb);
    size = parse_string_to_int(mb);
    printf("%dmb to allocate\n", size);
    printf("PID: %d\n", getpid());
  }

  char mem[size * 1024];
  int i = 0;
  while (1) {
    mem[i] = 'a';
    i = i <= 1023 ? i + 1 : i % 1024;
  }
  return 0;
}
