//
// Created by illyum on 6/6/2024.
//

#include <string>
#include <algorithm>
#include <sstream>
#include "strmanip.hpp"


namespace strmanip {
    std::string to_upper(const std::string &str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    std::string to_lower(const std::string &str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    std::vector<std::string> split(const std::string &str, char delim) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::string replace(const std::string &str, const std::string &from, const std::string &to) {
        std::string result = str;
        size_t start_pos = 0;
        while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
            result.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return result;
    }

    bool contains(const std::string &str, const std::string &inner) {
        // Note: "found!" will be printed if s2 is a substring of s1, both s1 and s2 are of type std::string.
        if (str.find(inner) != std::string::npos) {
            return true;
        }
        return false;
    }

    std::wstring toWideString(const std::string &str) {
        int sizeNeeded = MultiByteToWideChar(
                CP_UTF8,
                0,
                str.c_str(),
                (int) str.size(),
                nullptr,
                0
        );
        std::wstring wstr(sizeNeeded, 0);
        MultiByteToWideChar(
                CP_UTF8,
                0,
                str.c_str(),
                (int) str.size(),
                &wstr[0],
                sizeNeeded
        );
        return wstr;
    }

}
