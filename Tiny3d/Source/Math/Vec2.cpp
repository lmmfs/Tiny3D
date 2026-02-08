#include "Vec2.h"

namespace  Tiny3d {

    Vec2::Vec2(): x(0.0f), y(0.0f) {}

    Vec2::Vec2(float scalar): x(scalar), y(scalar) {}

    Vec2::Vec2(float x, float y): x(x), y(y) {}

    Vec2& Vec2::add(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& Vec2::sub(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& Vec2::multiply(const Vec2& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vec2& Vec2::divide(const Vec2& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }


    Vec2& Vec2::add(float value) {
        x += value;
        y += value;
        return *this;
    }

    Vec2& Vec2::sub(float value) {
        x -= value;
        y -= value;
        return *this;
    }

    Vec2& Vec2::multiply(float value) {
        x *= value;
        y *= value;
        return *this;
    }

    Vec2& Vec2::divide(float value) {
        x /= value;
        y /= value;
        return *this;
    }

}
