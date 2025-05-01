#pragma once
#include <type_traits>
#include <functional>

namespace EnumClassHash
{
    template<typename T> //템플릿으로 정의함
    struct Hash
    {
        static_assert(std::is_enum_v<T>, "여기엔 오직 enumclass해시만 쓸수있어!");
        size_t operator()(T value) const noexcept
        {
            return static_cast<size_t>(value);
        }
    };
}
//std가 이걸 이렇게 쓸수도 있게 선언해주기
namespace std
{
    template<typename T>
    requires std::is_enum_v<T>
    struct hash<T> : EnumClassHash::Hash<T> {};
}