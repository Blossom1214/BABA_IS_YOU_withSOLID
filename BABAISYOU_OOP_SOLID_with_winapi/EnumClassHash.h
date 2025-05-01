#pragma once
#include <type_traits>
#include <functional>

namespace EnumClassHash
{
    template<typename T> //���ø����� ������
    struct Hash
    {
        static_assert(std::is_enum_v<T>, "���⿣ ���� enumclass�ؽø� �����־�!");
        size_t operator()(T value) const noexcept
        {
            return static_cast<size_t>(value);
        }
    };
}
//std�� �̰� �̷��� ������ �ְ� �������ֱ�
namespace std
{
    template<typename T>
    requires std::is_enum_v<T>
    struct hash<T> : EnumClassHash::Hash<T> {};
}