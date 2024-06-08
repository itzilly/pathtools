//
// Created by illyum on 6/6/2024.
//

#ifndef DEVTOOLS_STRMANIP_HPP
#define DEVTOOLS_STRMANIP_HPP

#include <string>
#include <vector>
#include <stringapiset.h>


namespace strmanip {
    std::string to_upper(const std::string &str);

    std::string to_lower(const std::string &str);

    std::vector<std::string> split(const std::string &str, char delim);

    std::string replace(const std::string &str, const std::string &from, const std::string &to);

    bool contains(const std::string &str, const std::string &inner);

    std::wstring toWideString(const std::string &str);
}


#endif //DEVTOOLS_STRMANIP_HPP
