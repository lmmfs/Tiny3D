#pragma once

namespace Tiny3d {
    struct Vec2 {
        float x, y;

        Vec2();
		Vec2(float scalar);
		Vec2(float x, float y);

        Vec2& add(const Vec2& other);
        Vec2& sub(const Vec2& other);
        Vec2& multiply(const Vec2& other);
        Vec2& divide(const Vec2& other);


        Vec2& add(float value);
        Vec2& sub(float value);
        Vec2& multiply(float value);
        Vec2& divide(float value);
    };

}
