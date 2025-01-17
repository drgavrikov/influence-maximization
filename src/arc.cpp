#include "arc.h"

void Arc::write(std::ofstream &file) const {
    if (!file) {
        throw std::ios_base::failure("Failed to write to file.");
    }

    file.write(reinterpret_cast<const char *>(&source), sizeof(source));
    file.write(reinterpret_cast<const char *>(&target), sizeof(target));
    file.write(reinterpret_cast<const char *>(&weight), sizeof(weight));
    file << std::endl;
}

bool Arc::operator<(const Arc &other) const {
    return source < other.source || (source == other.source && target < other.target);
}

Arc Arc::readArc(std::ifstream &file) {
    if (!file) {
        throw std::ios_base::failure("Failed to read from file.");
    }

    Arc arc{};
    file.read(reinterpret_cast<char *>(&arc.source), sizeof(arc.source));
    file.read(reinterpret_cast<char *>(&arc.target), sizeof(arc.target));
    file.read(reinterpret_cast<char *>(&arc.weight), sizeof(arc.weight));
    file.ignore();

    return arc;
}
