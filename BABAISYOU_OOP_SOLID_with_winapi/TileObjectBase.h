#pragma once
class TileObjectBase
{
public:
    virtual ~TileObjectBase() = default;

    virtual void Render() = 0;
};