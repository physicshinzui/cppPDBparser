#include <iostream> 
#include <fstream> 
#include <string>
#include "PDB.h"

PDB::PDB()  {

};
PDB::~PDB() {

};

void PDB::load(std::string pdb_file) {
    std::ifstream file_obj;//ifstream is for reading, whereas ofstream is for writing.
    std::string line;

    file_obj.open(pdb_file, std::ios::in); //ios::out is the default of "ofstream"

    if (file_obj.is_open()) {

        //We have created a while loop that reads the file line by line, using getline. 
        int atom_counter {0};
        while (std::getline(file_obj, line)) {

            // Only ATOM or HETATM lines are read. 
            std::string atom_row = line.substr(0,6);  //0 to 0 + 6 elements are extracted 
            if (atom_row=="ATOM  " || atom_row == "HETATM") { 
                //PDB format is based on https://cupnet.net/pdb-format/
                std::string atom_num   = line.substr(6,5);
                std::string blank1     = line.substr(11,1);                        
                std::string atom_name  = line.substr(12,4);
                std::string alt_loc_id = line.substr(16,1);
                std::string res_name   = line.substr(17,3);
                std::string blank2     = line.substr(20,1);                  
                std::string chain_id   = line.substr(21,1);
                std::string res_num    = line.substr(22,4);
                std::string code_insert= line.substr(26,1);
                std::string blank3     = line.substr(27,3);
                std::string x          = line.substr(30,8);
                std::string y          = line.substr(38,8);
                std::string z          = line.substr(46,8);
                std::string occupancy  = line.substr(54,6);
                std::string bfactor    = line.substr(60,6);
                std::string blank4     = line.substr(66,10);
                std::string elem_symbol= line.substr(76,2);
                std::string charge     = line.substr(78,2);
                
                //std::cout << line << std::endl;
                std::cout << atom_row << atom_num << blank1 << atom_name << alt_loc_id << res_name << blank2 << chain_id << res_num << code_insert << blank3 << x << y << z << occupancy << bfactor << blank4 << elem_symbol << charge << std::endl;
                ++atom_counter;
            }
        }
        _natoms = atom_counter;
        file_obj.close();
    
    } else {

        std::cout << "Unable to open file" << std::endl;

    }
}

int PDB::get_natoms() {
    return _natoms;
}