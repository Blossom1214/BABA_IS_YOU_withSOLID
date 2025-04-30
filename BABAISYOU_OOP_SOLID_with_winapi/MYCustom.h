#pragma once
#include <cstddef>
#include <type_traits>

namespace MYCustom::Uitility::Hash
{
	struct EnumclassHash
	{
		template<typename T>
		std::size_t operator()(T t) const noexcept
		{
			static_assert(std::is_enum_v<T>, "EnumClassHash는 enum 타입에만 사용하세요.");
			return static_cast<std::size_t>(t);
		}
	};
}