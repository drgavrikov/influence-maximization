#ifndef INFLUENCE_MAXIMIZATION_ARC_H
#define INFLUENCE_MAXIMIZATION_ARC_H

#include <cstdint>
#include <fstream>
#include <stdexcept>

struct Arc {
    uint32_t source;
    uint32_t target;
    double weight;

    static constexpr size_t record_size() noexcept;

    void write(std::ofstream &file) const;

    bool operator<(const Arc &other) const;

    static Arc readArc(std::ifstream &file);
};

#endif //INFLUENCE_MAXIMIZATION_ARC_H
