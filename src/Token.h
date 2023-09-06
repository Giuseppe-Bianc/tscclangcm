#pragma once

#include "headers.h"

enum class TokType {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_SLASH,
    TOKEN_EOF,
    TOKEN_ERROR
    // Add more token types here
};

class Token {
public:
#pragma optimize("gt", on)
    inline Token(TokType t, std::string_view v) : type(t), value(v) {}
#pragma optimize("gt", on)
    inline TokType getType() const noexcept { return type; }
#pragma optimize("gt", on)
    inline const std::string &getValue() const noexcept { return value; }
#pragma optimize("gt", on)
    std::string toString() const {
        if(!value.empty()) [[likely]] {
            return std::format(R"(Token(Type: {}, Value: {}))", tokenTypeToString(type), value);
        }
        return std::format(R"(Token(Type: {}))", tokenTypeToString(type));
    }

private:
#pragma optimize("gt", on)
    inline static std::string tokenTypeToString(TokType type) {
        switch(type) {
            using enum TokType;
        case TOKEN_INT:
            return "TOKEN_INT";
        case TOKEN_PLUS:
            return "TOKEN_PLUS";
        case TOKEN_MINUS:
            return "TOKEN_MINUS";
        case TOKEN_SLASH:
            return "TOKEN_SLASH";
        case TOKEN_EOF:
            return "TOKEN_EOF";
        case TOKEN_ERROR:
            return "TOKEN_ERROR";
            // Handle other token types
        }
        return "Unknown TokenType";
    }
    const TokType type;
    const std::string value;
};
