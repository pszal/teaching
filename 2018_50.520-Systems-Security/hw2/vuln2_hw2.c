//vuln.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void validate_passwd(char* passwd) {
 char passwd_buf[7];
 unsigned char passwd_len = strlen(passwd); /* [1] */ 
 if(passwd_len >= 4 && passwd_len <= 8) { /* [2] */
  printf("Valid Password\n"); /* [3] */ 
  fflush(stdout);
  strcpy(passwd_buf,passwd); /* [4] */
 } else {
  printf("Invalid Password\n"); /* [5] */
  fflush(stdout);
 }

int main(int argc, char* argv[]) {
 if(argc!=2) {
  printf("Usage Error:   \n");
  fflush(stdout);
  exit(-1);
 }
 validate_passwd(argv[1]);
 return 0;
}