//
// Created by illyum on 6/6/2024.
//

#include <cstdio>
#include <string>
#include <fileapi.h>
#include <handleapi.h>
#include <errhandlingapi.h>
#include "strmanip.hpp"
#include "touch.hpp"


int main(int argc, char **argv) {
    if (argc <= 1) {
        printUsage();
        return 0;
    }

    if (strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0) {
        printUsage();
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        // Debug stuff
        // printf("Argument %d: %s\n", i, argv[i]);
        createFile(argv[i]);
    }
    return 0;
}

void printUsage() {
    printf("Usage: touch <filename>...\n");
    printf("Example: touch file1.txt\n");
//    printf("touch will create folder tree if it does not already exist\n");
//    printf("Example: touch folder2/file2.txt\n");
}

WINBOOL createFile(const char *name) {
    std::string strName(name);
    std::string replaced = strmanip::replace(strName, "\\", "/");
    std::vector<std::string> filetree = strmanip::split(replaced, '/');
    if (strmanip::contains(replaced, "/")) {
        printf("Unable to create file tree: NOT_IMPLEMENTED\n");
        return 0;
    }

// This no work yet
//    std::string path;
//    for (size_t i = 0; i < filetree.size() - 1; ++i) {
//        path += filetree[i] + "/";
//        createFolder(path);
//    }

    std::wstring wname = strmanip::toWideString(replaced);
    HANDLE handle = CreateFileW(
            wname.c_str(),
            GENERIC_WRITE,
            0,
            nullptr,
            CREATE_NEW,
            FILE_ATTRIBUTE_NORMAL,
            nullptr
    );
    if (handle == INVALID_HANDLE_VALUE) {
        // 80 (Already Exists?)
        // 123 (Invalid Characters?)
        printf("Failed to create file: %lu\n", GetLastError());
        return 0;
    }

    printf("Created file: %s\n", name);

    CloseHandle(handle);
    return 1;
}

WINBOOL createFolder(const std::string &name) {
    std::wstring wname = strmanip::toWideString(name);
    return CreateDirectoryW(wname.c_str(), nullptr);
}