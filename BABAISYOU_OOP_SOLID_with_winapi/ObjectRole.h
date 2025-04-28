#pragma once
#include "ObjectType.h"

// 오브젝트가 행하는 문법
enum class ObjectRole {
    NONE,//없음
    TEXT,//text
    NOUN,//명사
    VERB,//동사
    PROPERTY//동작
};

// 오브젝트에 따라서 역할 분리..
inline ObjectRole GetObjectRole(ObjectType type) {
    switch (type) {
    case ObjectType::TEXT_BABA:
    case ObjectType::TEXT_ROCK:
    case ObjectType::TEXT_WALL:
    case ObjectType::TEXT_FLAG:
        return ObjectRole::NOUN;

    case ObjectType::TEXT_IS:
        return ObjectRole::VERB;

    case ObjectType::TEXT_YOU:
    case ObjectType::TEXT_PUSH:
    case ObjectType::TEXT_STOP:
    case ObjectType::TEXT_WIN:
        return ObjectRole::PROPERTY;

    default:
        return ObjectRole::NONE;
    }
}