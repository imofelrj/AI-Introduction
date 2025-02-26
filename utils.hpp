#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdio>
#include <cctype>
#include <string>

namespace fastio {

const int IN_BUF_SIZE = 1 << 20; // 1MB input buffer
char in_buffer[IN_BUF_SIZE];
size_t in_pos = 0, in_len = 0;

inline int getChar() {
    if (in_pos == in_len) {
        in_len = fread(in_buffer, 1, IN_BUF_SIZE, stdin);
        if (in_len == 0) return EOF;
        in_pos = 0;
    }
    return in_buffer[in_pos++];
}

template<typename T>
inline bool readInt(T &number) {
    int c = getChar();
    while (c != EOF && isspace(c)) c = getChar();
    if (c == EOF) return false;
    bool neg = false;
    if (c == '-') { 
        neg = true;
        c = getChar();
    }
    number = 0;
    for (; c != EOF && isdigit(c); c = getChar()) {
        number = number * 10 + (c - '0');
    }
    if (neg)
        number = -number;
    return true;
}

inline bool readDouble(double &number) {
    int c = getChar();
    while (c != EOF && isspace(c)) c = getChar();
    if (c == EOF) return false;
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getChar();
    }
    double intPart = 0;
    while (c != EOF && isdigit(c)) {
        intPart = intPart * 10 + (c - '0');
        c = getChar();
    }
    double fracPart = 0, divisor = 1;
    if (c == '.') {
        c = getChar();
        while (c != EOF && isdigit(c)) {
            fracPart = fracPart * 10 + (c - '0');
            divisor *= 10;
            c = getChar();
        }
    }
    number = intPart + fracPart / divisor;
    if (neg)
        number = -number;
    return true;
}

inline bool readString(std::string &str) {
    str.clear();
    int c = getChar();
    while (c != EOF && isspace(c)) c = getChar();
    if (c == EOF) return false;
    while (c != EOF && !isspace(c)) {
        str.push_back((char)c);
        c = getChar();
    }
    return true;
}

// Fast output
const int OUT_BUF_SIZE = 1 << 20; // 1MB output buffer
char out_buffer[OUT_BUF_SIZE];
int out_pos = 0;

inline void flush() {
    if (out_pos) {
        fwrite(out_buffer, 1, out_pos, stdout);
        out_pos = 0;
    }
}

inline void putChar(char c) {
    if (out_pos == OUT_BUF_SIZE)
        flush();
    out_buffer[out_pos++] = c;
}

template<typename T>
inline void writeInt(T number, char end = '\n') {
    if (number == 0) {
        putChar('0');
    } else {
        if (number < 0) {
            putChar('-');
            number = -number;
        }
        char buf[20];
        int idx = 0;
        while (number) {
            buf[idx++] = (char)('0' + number % 10);
            number /= 10;
        }
        while (idx--)
            putChar(buf[idx]);
    }
    putChar(end);
}

inline void writeString(const std::string &str, char end = '\n') {
    for (const char c : str)
        putChar(c);
    putChar(end);
}

} // namespace fastio

#endif // UTILS_HPP