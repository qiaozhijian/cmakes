//
// Created by qzj on 2020/6/24.
//

#ifndef RENAMEIMAGE_UTIL_H
#define RENAMEIMAGE_UTIL_H

#include <boost/regex.hpp> //Note: using boost regex instead of C++11 regex as it isn't supported by the compiler until gcc 4.9
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

void getSortedImages(const boost::filesystem::path &img_dir, std::function<bool(const std::string &)> filter,
                     std::function<bool(const std::string &, const std::string &)> comparator, std::vector<std::string> &img_paths);

#endif //RENAMEIMAGE_UTIL_H
