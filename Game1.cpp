#include <SFML/Graphics.hpp>
#include <SFML/window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"

#include <iostream>

using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Paddle& paddle, Ball& ball) {
    if (!isIntersecting(paddle, ball)) return false;
    ball.moveUp();
    if (ball.getPosition().x < paddle.getPosition().x) ball.moveLeft();
    else if(ball.getPosition().x > paddle.getPosition().x) ball.moveRight();
}

bool collisionTest(Block& block, Ball& ball) {
    if (!isIntersecting(block, ball)) return false;
    block.destroy();

    float overlapeLeft{ ball.right() - block.left() };
    float overlapeRight{ block.right() - ball.left() };

    float overlapeTop{ ball.bottom() - block.top() };
    float overlapeBottom{ block.bottom() - ball.top() };

    bool ballFromLeft{ abs(overlapeLeft) < abs(overlapeRight) };
    bool ballFromTop{ abs(overlapeTop) < abs(overlapeBottom) };

    float minOverlapX{ ballFromLeft ? overlapeLeft : overlapeRight };
    float minOverlapY{ ballFromTop ? overlapeTop : overlapeBottom };

    if (abs(minOverlapX) < abs(minOverlapY)) {
        ballFromLeft ? ball.moveLeft() : ball.moveRight();
    } else {
        ballFromTop ? ball.moveUp() : ball.moveDown();
    }
}

int main() {
    RenderWindow window{ VideoMode(800, 600), "Arcanoid" };
    window.setFramerateLimit(60);

    Event ev{};
    Ball ball(400, 300);
    Paddle paddle(400, 550);

    unsigned blocksX{ 10 }, blocksY{ 4 }, blockWidth{ 60 }, blockHeight{ 20 };

    vector<Block> blocks;

    for (int i = 0; i < blocksY; i++) {
        for (int j = 0; j < blocksX; j++) {
            blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }

    while (window.isOpen()) {
        window.clear(Color::Black);
        ;
        while (window.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                window.close();
                break;
            }
        }
        
        ball.update();
        paddle.update();

        collisionTest(paddle, ball);
        for (auto& obj : blocks) if (collisionTest(obj, ball)) break;

        auto iterator = remove_if(begin(blocks), end(blocks), [] (Block& block) {return block.isDestroyed(); });
        blocks.erase(iterator, end(blocks));

        window.draw(ball);
        window.draw(paddle);
        for (auto& obj : blocks)  window.draw(obj);

        window.display();
    }
    return 0;
}