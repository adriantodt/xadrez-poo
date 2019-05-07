#include "mathutils.h"

/**
 * Retorna o sinal do número.
 */
int sgn(int v) {
    return (v > 0) ? 1 : ((v < 0) ? -1 : 0);
}