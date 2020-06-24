//
// Created by qzj on 2020/6/24.
//
#include "util.h"


void getSortedImages(const boost::filesystem::path &img_dir, std::function<bool(const std::string &)> filter,
                     std::function<bool(const std::string &, const std::string &)> comparator, std::vector<std::string> &img_paths) {

    // get a sorted list of files in the img directories
    if (!boost::filesystem::exists(img_dir) ||
        !boost::filesystem::is_directory(img_dir))
        throw std::runtime_error("[Dataset] Invalid images subfolder");

    // get all files in the img directories
    std::list<std::string> all_imgs;
    for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(img_dir), {})) {
        boost::filesystem::path filename_path = entry.path().filename();
        if (boost::filesystem::is_regular_file(entry.status()) &&
            (filename_path.extension() == ".png"  ||
             filename_path.extension() == ".jpg"  ||
             filename_path.extension() == ".jpeg" ||
             filename_path.extension() == ".pnm"  ||
             filename_path.extension() == ".tiff")) {
            all_imgs.push_back(filename_path.string());
        }
    }

    // sort
    img_paths.clear();
    img_paths.reserve(all_imgs.size());
    for (const std::string &filename : all_imgs)
        if (!filter(filename)) img_paths.push_back(filename);

    if (img_paths.empty())
        throw std::runtime_error("[Dataset] Invalid image names?");

    std::sort(img_paths.begin(), img_paths.end(), comparator);

    for (std::string &filename : img_paths)
        filename = (img_dir / filename).string();
}