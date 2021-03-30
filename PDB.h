#ifndef PDB_H
#define PDB_H

#include <string>
class PDB {
    private:
        int _natoms {0};

    public:
        PDB();
        ~PDB();
        void load(std::string pdb_file); 
        int get_natoms();
};

#endif