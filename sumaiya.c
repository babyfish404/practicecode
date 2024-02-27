
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

// Function to check if a string is a keyword
bool isKeyword(const std::string& word) {
    static const std::set<std::string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
        "long", "register", "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    return keywords.find(word) != keywords.end();
}

int main() {
    std::string input;

    std::cout << "Enter a line for lexical analysis: ";
    std::getline(std::cin, input);

    std::istringstream stream(input);

    // Vectors to store different types of tokens
    std::vector<std::string> keywords;
    std::vector<std::string> identifiers;
    std::vector<std::string> constants;
    std::vector<std::string> operators;
    std::vector<std::string> punctuation;

    std::string token;
    while (stream >> token) {
        if (isKeyword(token))
            keywords.push_back(token);
        else if (isalpha(token[0])) // Identifier
            identifiers.push_back(token);
        else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) // Constant (including negative numbers)
            constants.push_back(token);
        else if (token.length() == 1) // Single character token
            punctuation.push_back(token);
        else if (token == "(" || token == ")" || token == "{" || token == "}" || token == "[" || token == "]")
            punctuation.push_back(token);
        else if (token == ";" || token == ":" || token == ",")
            punctuation.push_back(token);
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "=" ||
                 token == ">" || token == ">=" || token == "<" || token == "<=" ||
                 token == "==" || token == "!=")
            operators.push_back(token);
    }

    // Display the extracted tokens
    std::cout << "Keyword (" << keywords.size() << "): ";
    for (const auto& kw : keywords)
        std::cout << kw << " ";

    std::cout << "\nIdentifier (" << identifiers.size() << "): ";
    for (const auto& id : identifiers)
        std::cout << id << " ";

    std::cout << "\nArithmetic Operator (" << operators.size() << "): ";
    for (const auto& op : operators)
        std::cout << op << " ";

    std::cout << "\nConstant (" << constants.size() << "): ";
    for (const auto& cst : constants)
        std::cout << cst << " ";

    std::cout << "\nPunctuation (" << punctuation.size() << "): ";
    for (const auto& punct : punctuation)
        std::cout << punct << " ";

    std::cout << std::endl;

    return 0;
}
