//
// Created by illyum on 6/6/2024.
//

#ifndef DEVTOOLS_TOUCH_HPP
#define DEVTOOLS_TOUCH_HPP


int main(int argc, char *argv[]);
void printUsage();
const char* reservedCharacters[7] = {"<", ">", ":", "\"", "|", "?", "*"};
WINBOOL createFile(const char *name);
WINBOOL createFolder(const std::string &name);

#endif //DEVTOOLS_TOUCH_HPP