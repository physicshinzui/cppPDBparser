#ifndef PDB_H
#define PDB_H

#include <string>
class PDB {
    private:

    public:
        PDB();
        ~PDB();
        void load(std::string pdb_file); 
};

#endif