#pragma once
#include <cstdint>
#include <string_view>


enum class Tag : uint8_t
{
    none        = 0,
    sand        = 1,
    // Add your own...

    COUNT  // always last lets you size arrays, validate, etc.
};
