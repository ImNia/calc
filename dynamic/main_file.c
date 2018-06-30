#include <stdlib.h>

int main()
{
    setenv("LD_LIBRARY_PATH", "./", 1);
    system("./c_file/test");
    return 0;
}
