#pragma once
#include"ObjectType.h"
enum class TextRole
{
    NONE,       // 아무것도 아님
    BABA,       // "BABA" 텍스트
    ROCK,       // "ROCK" 텍스트
    WALL,       // "WALL" 텍스트
    FLAG,       // "FLAG" 텍스트
    IS,         // "IS" 텍스트 (동사)
    AND,        // "AND" 텍스트 (연결자)
    YOU,        // "YOU" 텍스트 (속성)
    PUSH,       // "PUSH" 텍스트 (속성)
    STOP,       // "STOP" 텍스트 (속성)
    WIN,        // "WIN" 텍스트 (속성)
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