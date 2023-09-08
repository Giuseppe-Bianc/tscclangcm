#pragma once
#include "Token.h"

class Lexer {
public:
#pragma optimize("gt", on)
    inline explicit Lexer(const std::string_view &source) : source_(source), sourceSize(source.size()) {}
#pragma optimize("gt", on)
    inline std::vector<Token> getAllTokens() {
        std::vector<Token> tokens;
        tokens.reserve(sourceSize);  // Reserve enough space to avoid reallocations

        using enum TokType;

        while(position_ < sourceSize) {
            // Skip whitespace characters
            while(position_ < sourceSize && std::isspace(source_.at(position_))) {
                ++position_;
            }

            if(position_ >= sourceSize) {
                break;  // Reached the end of the source
            }

            const char currentChar = source_.at(position_);

            if(std::isdigit(currentChar)) {
                const size_t start = position_;
                while(position_ < sourceSize && std::isdigit(source_.at(position_))) {
                    ++position_;
                }
                tokens.emplace_back(T_INT, source_.substr(start, position_ - start));
            } else {
                switch(currentChar) {
                case '+':
                    tokens.emplace_back(T_PLUS, "+");
                    break;
                case '-':
                    tokens.emplace_back(T_MINUS, "-");
                    break;
                case '/':
                    tokens.emplace_back(T_SLASH, "/");
                    break;
                case '%':
                    tokens.emplace_back(T_MODULUS, "%");
                    break;
                case '^':
                    tokens.emplace_back(T_CARET, "^");
                    break;
                default:
                    tokens.emplace_back(T_ERROR, std::string_view(&currentChar, 1));
                    break;
                }
                ++position_;
            }
        }

        tokens.emplace_back(TokType::T_EOF, "");  // Add EOF token
        return tokens;
    }

private:
    const std::string source_;
    const std::size_t sourceSize;
    size_t position_ = 0;
};
