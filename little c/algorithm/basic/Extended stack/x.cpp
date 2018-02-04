const int main_stack=16;
char my_stack[128<<20];

void MAIN() {
    //your code
}

int main() {
    __asm__("movl %%esp, (%%eax);\n"::"a"(my_stack):"memory");
    __asm__("movl %%eax, %%esp;\n"::"a"(my_stack+sizeof(my_stack)-main_stack):"%esp");
    MAIN();
    __asm__("movl (%%eax), %%esp;\n"::"a"(my_stack):"%esp");
    return 0;
}
