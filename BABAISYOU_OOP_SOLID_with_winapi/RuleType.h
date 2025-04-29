#pragma once
enum class RuleType
{
    NONE,   // 기본 상태
    YOU,    // 조작 가능
    PUSH,   // 밀림
    STOP,   // 이동 불가
    WIN,    // 승리 판정
};
