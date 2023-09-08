#pragma once

#include "headers.h"

enum class TokType {
    T_INT,
    T_PLUS,
    T_MINUS,
    T_SLASH,
    T_CARET,
    T_MODULUS,
    T_EOF,
    T_ERROR
    // Add more token types here
};

class Token {
public:
#pragma optimize("gt", on)
    constexpr Token(TokType t, const std::string_view &v) : type(t), value(v) {}
#pragma optimize("gt", on)
    constexpr TokType getType() const noexcept { return type; }
#pragma optimize("gt", on)
    constexpr std::string_view getValue() const noexcept { return value; }
#pragma optimize("gt", on)
    constexpr std::string toString() const {
        if(!value.empty()) [[likely]] {
            return std::format(R"(Token({}, Value: {}))", tokenTypeToString(type), value);
        }
        return std::format(R"(Token({}))", tokenTypeToString(type));
    }

private:
#pragma optimize("gt", on)
    constexpr static std::string_view tokenTypeToString(TokType type) {
        using enum TokType;
        switch(type) {
        case T_INT:
            return "T_INT";
        case T_PLUS:
            return "T_PLUS";
        case T_MINUS:
            return "T_MINUS";
        case T_SLASH:
            return "T_SLASH";
        case T_CARET:
            return "T_CARET";
        case T_MODULUS:
            return "T_MODULUS";
        case T_EOF:
            return "T_EOF";
        case T_ERROR:
            return "T_ERROR";
        default:
            return "Unknown TokenType";
        }
    }

    const TokType type;
    const std::string value;
};
