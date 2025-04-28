#pragma once
#include"ObjectType.h"
enum class TextRole
{
    NONE,       // �ƹ��͵� �ƴ�
    BABA,       // "BABA" �ؽ�Ʈ
    ROCK,       // "ROCK" �ؽ�Ʈ
    WALL,       // "WALL" �ؽ�Ʈ
    FLAG,       // "FLAG" �ؽ�Ʈ
    IS,         // "IS" �ؽ�Ʈ (����)
    AND,        // "AND" �ؽ�Ʈ (������)
    YOU,        // "YOU" �ؽ�Ʈ (�Ӽ�)
    PUSH,       // "PUSH" �ؽ�Ʈ (�Ӽ�)
    STOP,       // "STOP" �ؽ�Ʈ (�Ӽ�)
    WIN,        // "WIN" �ؽ�Ʈ (�Ӽ�)
};
inline TextRole GetTextRole(ObjectType type)
{
    switch (type)
    {
    case ObjectType::TEXT_BABA: return TextRole::BABA;
    case ObjectType::TEXT_ROCK: return TextRole::ROCK;
    case ObjectType::TEXT_WALL: return TextRole::WALL;
    case ObjectType::TEXT_FLAG: return TextRole::FLAG;
    case ObjectType::TEXT_IS:   return TextRole::IS;
    case ObjectType::TEXT_YOU:  return TextRole::YOU;
    case ObjectType::TEXT_PUSH: return TextRole::PUSH;
    case ObjectType::TEXT_STOP: return TextRole::STOP;
    case ObjectType::TEXT_WIN:  return TextRole::WIN;

    default: return TextRole::NONE;
    }
}