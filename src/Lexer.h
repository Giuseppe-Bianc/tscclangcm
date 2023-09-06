#pragma once
#include "Token.h"

class Lexer {
public:
#pragma optimize("gt", on)
    inline explicit Lexer(const std::string& source) : source_(source), sourceSize(source.size()) {}
#pragma optimize("gt", on)
    inline std::vector<Token> getAllTokens() {
        std::vector<Token> tokens;
        tokens.reserve(sourceSize);  // Reserve enough space to avoid reallocations

        using enum TokType;

        while (position_ < sourceSize) {

            // Skip whitespace characters
            while (position_ < sourceSize && std::isspace(source_.at(position_))) {
                ++position_;
            }

            if (position_ >= sourceSize) {
                break; // Reached the end of the source
            }

            const char currentChar = source_.at(position_);

            if (std::isdigit(currentChar)) {
                size_t start = position_;
                while (position_ < sourceSize && std::isdigit(source_.at(position_))) {
                    ++position_;
                }
                tokens.emplace_back(TOKEN_INT, std::move(source_.substr(start, position_ - start)));
            }
            else {
                switch (currentChar) {
                case '+':
                    tokens.emplace_back(TOKEN_PLUS, "+");
                    break;
                case '-':
                    tokens.emplace_back(TOKEN_MINUS, "-");
                    break;
                case '/':
                    tokens.emplace_back(TOKEN_SLASH, "/");
                    break;
                default:
                    tokens.emplace_back(TOKEN_ERROR, std::move(std::string(1, currentChar)));
                    break;
                }
                ++position_;
            }
        }

        tokens.emplace_back(TokType::TOKEN_EOF, ""); // Add EOF token
        return tokens;
    }

private:
    const std::string source_;
    const std::size_t sourceSize;
    size_t position_ = 0;
};