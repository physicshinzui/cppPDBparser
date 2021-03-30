#include "PDB.h"
#include <iostream>
int main() {
    PDB PDB_OJB;
    PDB_OJB.load("test_pdbs/1maz.pdb");
//    PDB_OJB.load("test_pdbs/6lu7.pdb");
    std::cout << PDB_OJB.get_natoms() << std::endl; 
}