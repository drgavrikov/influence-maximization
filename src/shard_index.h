#ifndef INFLUENCE_MAXIMIZATION_SHARD_INDEX_H
#define INFLUENCE_MAXIMIZATION_SHARD_INDEX_H

#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>

struct EdgeShardOffset {
    uint32_t source;
    uint16_t shard_id;
    std::streamoff offset;

    void write(std::ofstream &file) const;

    static EdgeShardOffset read(std::ifstream &file);
};

using ShardIndex = std::vector<EdgeShardOffset>;

#endif //INFLUENCE_MAXIMIZATION_SHARD_INDEX_H
