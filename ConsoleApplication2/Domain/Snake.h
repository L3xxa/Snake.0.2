#ifndef SNAKE_H
#define SNAKE_H

#include <deque>

struct SnakeSegment {
    int x, y;
};

class Snake {
public:
    Snake(int startX, int startY);
    void move(int dx, int dy);
    void grow();
    void reset(int startX, int startY);
    std::deque<SnakeSegment> getBody() const;

private:
    std::deque<SnakeSegment> body;
};

#endif
