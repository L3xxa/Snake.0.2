#include "Snake.h"

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
}

void Snake::move(int dx, int dy) {
    SnakeSegment newHead = {body.front().x + dx, body.front().y + dy};
    body.push_front(newHead);
    body.pop_back();
}

void Snake::grow() {
    SnakeSegment newHead = body.front();
    body.push_front(newHead); // Add a new segment at the head
}

void Snake::reset(int startX, int startY) {
    body.clear();
    body.push_back({startX, startY});
}

std::deque<SnakeSegment> Snake::getBody() const {
    return body;
}
