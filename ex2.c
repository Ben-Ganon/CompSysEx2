//
// Created by ben on 07/11/2021.
//

#include "ex2.h"
#include <limits.h>

magnitude add(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    if (aInt > 0 && bInt > 0 && (aInt + bInt) < 0) {
        return toMagnitude((a + b + INT_MAX) + 1);
    }
    else if (aInt < 0 && bInt < 0 && (aInt + bInt) > 0) {
        return toMagnitude(aInt + bInt -INT_MAX + 1);
    }
    else return toMagnitude(aInt + bInt);
}

magnitude sub(magnitude a, magnitude b) {
    int aInt = toInt(a);
    int bInt = toInt(b);
    bInt = -bInt;
    return add(toMagnitude(aInt), toMagnitude(bInt));
}
magnitude multi(magnitude a, magnitude b) {
    magnitude c = a;
    for (int i = 1; i < toInt(b); i++) {
        c = add(c, a);
    }
    return c;
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
    int z = x & INT_MAX;
    return -z;
}

