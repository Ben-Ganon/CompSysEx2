#include <stdio.h>
#include "ex2.h"
#include "math.h"
#include <limits.h>

int main() {
    unsigned int x = 0xffffffff;
    unsigned int y = 0x00000001;
    int min = INT_MIN;
    printf("%x\n", sub(x, y));
    printf("%x", toInt(min));
    return 0;
}
