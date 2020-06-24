#include <iostream>
#include "util.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    string dataset_path = "../../dataset/room216/01";

    boost::filesystem::path dataset_base(dataset_path);
    if (!boost::filesystem::exists(dataset_base) ||
        !boost::filesystem::is_directory(dataset_base))
        throw std::runtime_error("[Dataset] Invalid directory");

    boost::filesystem::path img_l_dir = dataset_base / "left";
    boost::filesystem::path img_r_dir = dataset_base / "right";

    boost::regex expression("^[^0-9]*([0-9]+\\.?+[0-9]*)[^0-9]*\\.[a-z]{3,4}$");
    boost::cmatch what;
    auto filename_filter = [&expression, &what](const std::string &s) {
        return !boost::regex_match(s.c_str(), what, expression);
    };

    auto sort_by_number = [&expression, &what](const std::string &a, const std::string &b) {
        double n1, n2;

        if (boost::regex_match(a.c_str(), what, expression))
            n1 = std::stod(what[1]);
        else
            throw std::runtime_error("[Dataset] Unexpected behaviour while sorting filenames");

        if (boost::regex_match(b.c_str(), what, expression))
            n2 = std::stod(what[1]);
        else
            throw std::runtime_error("[Dataset] Unexpected behaviour while sorting filenames");

        return (n1 < n2);
    };

    std::vector<std::string> img_l_paths, img_r_paths;
    getSortedImages(img_l_dir, filename_filter, sort_by_number, img_l_paths);
    getSortedImages(img_r_dir, filename_filter, sort_by_number, img_r_paths);

    if (img_l_paths.size() != img_r_paths.size())
        throw std::runtime_error("[Dataset] Left and right images");

    for(auto iter=img_l_paths.begin();iter!=img_l_paths.end();iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}