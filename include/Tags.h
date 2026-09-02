#pragma once
#include <cstdint>
#include <string_view>


enum Tag : uint8_t
{
    NONE,
    SAND,
    WATER,
    GRASS,
    SANDSTONE,
    ROCK,
    SMOKE,
    COUNT  // always last lets you size arrays, validate, etc.
};
