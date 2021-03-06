#pragma once
#include <vector>
#include <set>
#include <filesystem>

class FileSource {
public:
    FileSource();

    virtual ~FileSource();
    const std::vector<std::filesystem::path> getWallpapers() const;
    const std::filesystem::path getDatabase() const;

private:
    std::filesystem::path wallpaperPath{};
    const std::set<std::string> allowedExtensions{ ".jpg", ".png" };
};

