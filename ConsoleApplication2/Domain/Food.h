#ifndef FOOD_H
#define FOOD_H

struct Food {
    int x, y;
    
    void spawnFood(int width, int height, int size);
};

#endif