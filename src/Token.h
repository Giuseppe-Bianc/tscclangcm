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

inline static constexpr std::array<const std::string_view, C_ST(TokType::TOKEN_ERROR) + 1> tokTypeStrings = {
    "TOKEN_INT", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_SLASH", "TOKEN_EOF", "TOKEN_ERROR"};

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
            return std::format(R"(Token(Type: {}, Value: {}))", tokenTypeToString(type), value);
        }
        return std::format(R"(Token(Type: {}))", tokenTypeToString(type));
    }

private:
#pragma optimize("gt", on)
    constexpr static std::string_view tokenTypeToString(TokType type) {
        if(const auto index = C_ST(type); index < tokTypeStrings.size()) [[likely]] {
            return tokTypeStrings[index];
        }
        return "Unknown TokenType";
    }

    const TokType type;
    const std::string value;
};
