#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkValidString(char *s) {
  int leftMin = 0, leftMax = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(') {
      leftMin++;
      leftMax++;
    } else if (s[i] == ')') {
      leftMin--;
      leftMax--;
    } else if (s[i] == '*') {
      leftMax++;
      leftMin--;
    }
    if (leftMax < 0) {
      return false;
    }
    if (leftMin < 0) {
      leftMin = 0;
    }
  }
  return leftMin == 0;
}

int main() {
    char s[] = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    int result = checkValidString(s);
    printf("%s, result: %d\n", s, result);
}