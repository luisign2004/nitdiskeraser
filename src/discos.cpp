#include "../includes/discos.hpp"
#include <filesystem> 
#include <iostream>

namespace fs = std :: filesystem;

std :: vector <std :: string > listarDiscos(const std :: string & programaPath){
    std :: vector <std :: string> discos; 
    std::string rootPath;

#if defined(_WIN32) || defined(_WIN64)
    rootPath = "C:\\";
#elif defined(__linux__)
    rootPath = "/";
#elif defined(__APPLE__)
    rootPath = "/";
else
    std::cerr << "Sistema operacional não suportado" << std::endl;
    return discos;
#endif 
    try{
        for(const auto & entry : fs::directory_iterator(rootPath)){
            if(entry.is_directory() && entry.path().string() != programaPath){
                discos.push_back(entry.path().string());
            }
        }
    } catch(const fs::filesystem_error &e){
            std::cerr << "Erro ao acessar o sistema de arquivos:" << e.what() << std::endl;

    }

    return discos;
}