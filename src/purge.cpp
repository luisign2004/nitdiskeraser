#include "purge.hpp"
#include  <iostream>
#include  <fstream>
#include  <string>
#include  <vector>
#include  <iostream>
#include  <filesystem>

namespace fs = std::filesystem; 

// função de sobrescrever
bool overwriteFile(const std :: string & filePath, size_t passes = 3){
    try{
        std::ofstream file(filePath, std::ios::binary | std::ios::in);

        if (!file.is_open()){
            std::cerr << "Erro: Não foi possível abrir o arquivo para sobrescrever:" << filePath << std::endl;
        }

        size_t fileSize = fs::file_size(filePath); 
        for (size_t pass = 0; pass < passes; ++pass){
            file.seekp(0, std::ios::beg);
            for (size_t i = 0; i < fileSize; ++i){
                char randomByte = static_cast <char> (rand() % 256);
                file.put(randomByte);
            }
            file.flush();
        }
        file.close();
        return true;
    } catch (const std :: exception &e){
            std::cerr << "Erro ao sobrescrever o arquivo:" << e.what() << std::endl;
            return false;

    }
}

// função para excluir os arquivos


// função para processar arquivos

