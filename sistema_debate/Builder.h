#pragma once

class Builder {

public:

    virtual void reset() = 0;

    virtual ~Builder() = default;
};