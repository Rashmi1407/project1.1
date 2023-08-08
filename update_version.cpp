#include <iostream>
#include <fstream>
#include <regex>
#include <string>

std::string increment_version(const std::string &version) {
    int major, minor, patch;
    sscanf(version.c_str(), "%d.%d.%d", &major, &minor, &patch);
    patch++;
    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

int main() {
    std::ifstream inputFile("file2.txt");
    std::string content((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
    inputFile.close();

    std::regex versionPattern(R"((\d+\.\d+\.\d+))");
    std::string updatedContent = std::regex_replace(content, versionPattern, [&versionPattern](const std::smatch &match) {
        return increment_version(match.str(1));
    });

    std::ofstream outputFile("file2.txt");
    outputFile << updatedContent;
    outputFile.close();

    return 0;
}
