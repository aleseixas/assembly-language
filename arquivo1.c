int read(int __fd, const void *__buf, int __n){
    int ret_val;
  __asm__ __volatile__(
    "mv a0, %1           # file descriptor\n"
    "mv a1, %2           # buffer \n"
    "mv a2, %3           # size \n"
    "li a7, 63           # syscall write code (63) \n"
    "ecall               # invoke syscall \n"
    "mv %0, a0           # move return value to ret_val\n"
    : "=r"(ret_val)  // Output list
    : "r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
  return ret_val;
}

void write(int __fd, const void *__buf, int __n)
{
  __asm__ __volatile__(
    "mv a0, %0           # file descriptor\n"
    "mv a1, %1           # buffer \n"
    "mv a2, %2           # size \n"
    "li a7, 64           # syscall write (64) \n"
    "ecall"
    :   // Output list
    :"r"(__fd), "r"(__buf), "r"(__n)    // Input list
    : "a0", "a1", "a2", "a7"
  );
}

void exit(int code)
{
  __asm__ __volatile__(
    "mv a0, %0           # return code\n"
    "li a7, 93           # syscall exit (64) \n"
    "ecall"
    :   // Output list
    :"r"(code)    // Input list
    : "a0", "a7"
  );
}

void _start()
{
  int ret_code = main();
  exit(ret_code);
}

#define STDIN_FD  0
#define STDOUT_FD 1
//VETORES
char buffer[10];
char resultado[10];
char s1[10];
char s2[10];
char op[10];

char calculando(char s1, char op, char s2) {
  char resultado;
  if (op == '+')
    resultado = (s1 - 48)  + (s2 - 48) ;
  else if (op == '-')
    resultado = (s1 - 48) - (s2 - 48) ;
  else if (op == '*')
    resultado = (s1 - 48) * (s2 - 48);
  return resultado + 48;
}

int main(){
  write(STDOUT_FD,"0x", 2);
  char oi[10] = "1234567890";
  write(STDOUT_FD,oi,15);
  write(STDOUT_FD,"\n", 1);
}



