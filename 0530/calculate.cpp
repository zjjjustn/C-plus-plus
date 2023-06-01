#include <iostream>
#include <string>
#include <variant>
#include <optional>
#include <any>
#include <complex>

using Number = std::variant<int, double>;

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

std::optional<Number> parseNumber(const std::string& input) {
    try {
        int intValue = std::stoi(input);
        return intValue;
    }
    catch (const std::invalid_argument&) {
        try {
            double doubleValue = std::stod(input);
            return doubleValue;
        }
        catch (const std::invalid_argument&) {
            return std::nullopt;
        }
    }
}

std::any calculate(const Number& num1, const Number& num2, Operation operation) {
    try {
        switch (operation) {
        case Operation::Add:
            return std::visit([](auto&& a, auto&& b) { return a + b; }, num1, num2);
        case Operation::Subtract:
            return std::visit([](auto&& a, auto&& b) { return a - b; }, num1, num2);
        case Operation::Multiply:
            return std::visit([](auto&& a, auto&& b) { return a * b; }, num1, num2);
        case Operation::Divide:
            return std::visit([](auto&& a, auto&& b) { return a / b; }, num1, num2);
        }
    }
    catch (const std::bad_variant_access&) {
        return std::any();
    }
}

int main() {
    std::string input1 = "3.14";
    std::string input2 = "2";
    Operation operation = Operation::Add;

    std::optional<Number> num1 = parseNumber(input1);
    std::optional<Number> num2 = parseNumber(input2);

    if (num1.has_value() && num2.has_value()) {
        std::any result = calculate(*num1, *num2, operation);
        if (!result.has_value()) {
            Number res = std::any_cast<Number>(result);
            std::visit([](auto&& x) { std::cout << "Result: " << x << std::endl; }, res);
        }
        else {
            std::cout << "Invalid operation" << std::endl;
        }
    }
    else {
        std::cout << "Invalid input" << std::endl;
    }

    return 0;
}