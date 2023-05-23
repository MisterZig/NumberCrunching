#include <stdio.h>
#include <math.h> // For pow()

// Types of characters:
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define EXPONENTIATION 5
#define OPENING_BRACKET 6
#define CLOSING_BRACKET 7
#define NUMBER 8

int is_digit (char character) {
    return character >= '0' && character <= '9';
}

int isOperator (int type) {
    return type >= 1 && type <= 5;
}

int interpretCharacter (char character) {
    switch (character) {
        case '+':
            return 1;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 6;
        case ')':
            return 7;
        default:
            if (is_digit(character))
                return 8;
            else return 0;
    }
}

int calcuclate(char *expression) {
    int sections[(int) (sizeof(expression)/sizeof(expression[0])/3) + 1];
    int section_seperator_types[(int) (sizeof(expression)/sizeof(expression[0])/3) + 1];
    int current_section_value = 0;

    int section_start = 0; // Index of first character in section
    int depth = 0; // Depth of brackets
    int section_index = 0; // Current section
    int expecting_operator = 0; // boolean

    for (int i = 0; sizeof(expression)/sizeof(expression[0]); i++) {
        char current = expression[i];
        int type = interpretCharacter(current);

        if (type == 0) {
            printf("Invalid character: %c", current);
            return 0;
        } else if (type == NUMBER) {
            current_section_value += (current - '0') * pow(10, section_start-i); // Convert char to int
        } else if (type == OPENING_BRACKET) {
            depth++;
            section_index++;
            section_start = i-1;
        } else if (type == CLOSING_BRACKET) {
            depth--;
            sections[section_index] = current_section_value;
            expecting_operator = 1;
        } else if (isOperator(type)) {
            if (expecting_operator) {
                section_seperator_types[section_index] = type;
                expecting_operator = 0;
            } else {
                printf("Unexpected operator: %c", current);
                return 0;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < sizeof(sections)/sizeof(sections[0]); i++) {
        switch (section_seperator_types[i]) {
            case ADDITION:
                total += sections[i];
                break;
            case SUBTRACTION:
                total -= sections[i];
                break;
            case MULTIPLICATION:
                total *= sections[i];
                break;
            case DIVISION:
                total /= sections[i];
                break;
            case EXPONENTIATION:
                total = pow(total, sections[i]);
                break;
            default:
                break;
        }
    }
    return total;
}

int main() {
    char expression[] = "2+3*4";
    printf("%d", calcuclate(expression));
    return 0;
}