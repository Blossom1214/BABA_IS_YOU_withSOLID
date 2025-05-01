#pragma once
enum class ObjectType
{
	NONE,
	BABA,
	ROCK,
	WALL,
	FLAG,

	TEXT_BABA,
	TEXT_ROCK,
	TEXT_WALL,
	TEXT_FLAG,

	TEXT_STOP,
	TEXT_IS,
	TEXT_YOU,
	TEXT_WIN,
	TEXT_PUSH

};
inline bool isText(const ObjectType& type)
{
    switch (type)
    {
    case ObjectType::TEXT_BABA:
    case ObjectType::TEXT_ROCK:
    case ObjectType::TEXT_WALL:
    case ObjectType::TEXT_FLAG:
    case ObjectType::TEXT_STOP:
    case ObjectType::TEXT_IS:
    case ObjectType::TEXT_YOU:
    case ObjectType::TEXT_WIN:
    case ObjectType::TEXT_PUSH:
        return true;

    default:
        return false;
    }
}
inline bool isObject(ObjectType type)
{
    switch (type)
    {
    case ObjectType::BABA:
    case ObjectType::ROCK:
    case ObjectType::WALL:
    case ObjectType::FLAG:
        return true;

    default:
        return false;
    }
}
