//
// Created by ben on 07/11/2021.
//

#include "ex2.h"
#include <limits.h>

magnitude add(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    int c = aInt + bInt;
    return toMagnitude(c);
}

magnitude sub(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    int c = aInt - bInt;
    return toMagnitude(c);
}
magnitude multi(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    int c = aInt * bInt;
    return toMagnitude(c);
}

int equal(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    int c = aInt == bInt;
    return c;
}
int greater(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    int c = aInt > bInt;
    return c;
}

magnitude toMagnitude(int x) {
    if (x >= 0) {
        return x;
    }
    x = -x;
    return x | INT_MIN;
}

int toInt(magnitude x) {
    if (!(x & INT_MIN)) {
        return x;
    }
    x = x & INT_MAX;
    return -x;
}

