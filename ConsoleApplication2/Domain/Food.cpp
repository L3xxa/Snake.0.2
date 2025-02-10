
#include "Food.h"
#include <cstdlib>

void Food::spawnFood(int width, int height, int size) {
    x = rand() % (width / size) * size;
    y = rand() % (height / size) * size;
}
