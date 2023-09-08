#include <iostream>
#include <memory>
#include <sstream>
#include <string>

// Forward declaration of ASTNode class
class ASTNode;

// Define the possible binary operators
enum class BinaryOperator { ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, MOLDULUS, EXPONENTIATION };
enum class UnaryOperator { IDENTYTY, NEGATION };

// ASTNode class definition
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual constexpr double evaluate() const = 0;
    virtual std::string toString(int indent = 0) const = 0;
};

// BinaryOperatorNode class
class BinaryOperatorNode : public ASTNode {
public:
#pragma optimize("gt", on)
    inline const BinaryOperatorNode(BinaryOperator op, std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right) noexcept
        : op(op), left(left), right(right) {}
#pragma optimize("gt", on)
    constexpr double evaluate() const override {
        const double leftValue = left->evaluate();
        const double rightValue = right->evaluate();

        using enum BinaryOperator;
        switch(op) {
        case ADDITION:
            return leftValue + rightValue;
        case SUBTRACTION:
            return leftValue - rightValue;
        case MULTIPLICATION:
            return leftValue * rightValue;
        case DIVISION:
            if(rightValue != 0) {
                return leftValue / rightValue;
            } else {
                throw std::runtime_error("Division by zero");
            }
        case MOLDULUS:
            return std::fmod(leftValue, rightValue);
        case EXPONENTIATION:
            return std::pow(leftValue, rightValue);
        default:
            throw std::runtime_error("unhandled operation");
        }
    }
#pragma optimize("gt", on)
    inline std::string toString(int indent = 0) const override {
        std::stringstream ss;
        ss << std::string(indent, ' ') << "Binary Operator: ";
        using enum BinaryOperator;
        switch(op) {
        case ADDITION:
            ss << "+";
            break;
        case SUBTRACTION:
            ss << "-";
            break;
        case MULTIPLICATION:
            ss << "*";
            break;
        case DIVISION:
            ss << "/";
            break;
        }
        ss << "\n" << left->toString(indent + 2) << "\n" << right->toString(indent + 2);
        return ss.str();
    }

private:
    BinaryOperator op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
};

class UnaryOperatorNode : public ASTNode {
public:
#pragma optimize("gt", on)
    inline const UnaryOperatorNode(UnaryOperator op, std::shared_ptr<ASTNode> operand) noexcept : op(op), operand(operand) {}
#pragma optimize("gt", on)
    constexpr double evaluate() const override {
        const double operandValue = operand->evaluate();

        using enum UnaryOperator;
        switch(op) {
        case IDENTYTY:
            return operandValue;
        case NEGATION:
            return -operandValue;
        default:
            throw std::runtime_error("unhandled operation");
        }
    }
#pragma optimize("gt", on)
    inline std::string toString(int indent = 0) const override {
        std::stringstream ss;
        ss << std::string(indent, ' ') << "Unary Operator: ";
        switch(op) {
        case UnaryOperator::IDENTYTY:
            ss << "+";
            break;
        case UnaryOperator::NEGATION:
            ss << "-";
            break;
        }
        ss << "\n" << operand->toString(indent + 2);
        return ss.str();
    }

private:
    UnaryOperator op;
    std::shared_ptr<ASTNode> operand;
};

class NumberNode : public ASTNode {
public:
#pragma optimize("gt", on)
    explicit constexpr NumberNode(double value) : value(value) {}
#pragma optimize("gt", on)
    explicit constexpr NumberNode(int value) : value(C_D(value)) {}
#pragma optimize("gt", on)
    constexpr double evaluate() const override { return value; }
#pragma optimize("gt", on)
    inline std::string toString(int indent = 0) const override {
        std::stringstream ss;
        ss << std::string(indent, ' ') << "Number: " << value;
        return ss.str();
    }

private:
    double value;
};
