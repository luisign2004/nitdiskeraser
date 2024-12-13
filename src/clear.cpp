#include "clear.hpp"
#include "filesystem"
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void sobrescreverDados(const std :: string path, size_t passes){
    for (size_t i = 0; i < passes; i++){
        std :: cout << "Passagem " << i + 1 << " de " << passes << " em " << path << "\n";
        for (const auto &entry : fs::recursive_directory_iterator(path)){
            if(entry.is_regular_file()){
                std :: ofstream file (entry.path(), std::ios::binary);
                if (file.is_open()){
                    auto size = fs::file_size(entry.path());
                    for (size_t j = 0; j < size; ++j){
                        char data = (i % 2 == 0) ? 0x00 : 0xFF;
                        file.write(&data, 1);
                    }
                }
            }
        }

    }
}