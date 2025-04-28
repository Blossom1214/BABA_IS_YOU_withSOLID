#pragma once
#include "ObjectType.h"

// ������Ʈ�� ���ϴ� ����
enum class ObjectRole {
    NONE,//����
    TEXT,//text
    NOUN,//���
    VERB,//����
    PROPERTY//����
};

// ������Ʈ�� ���� ���� �и�..
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