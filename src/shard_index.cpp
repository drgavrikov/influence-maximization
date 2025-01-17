#include "shard_index.h"

void EdgeShardOffset::write(std::ofstream &file) const {
    if (!file) {
        throw std::ios_base::failure("Failed to write to file.");
    }

    file.write(reinterpret_cast<const char *>(&source), sizeof(source));
    file.write(reinterpret_cast<const char *>(&shard_id), sizeof(shard_id));
    file.write(reinterpret_cast<const char *>(&offset), sizeof(offset));
    file << std::endl;
}

EdgeShardOffset EdgeShardOffset::read(std::ifstream &file) {
    if (!file) {
        throw std::ios_base::failure("Failed to read from file.");
    }

    EdgeShardOffset entry{};
    file.read(reinterpret_cast<char *>(&entry.source), sizeof(entry.source));
    file.read(reinterpret_cast<char *>(&entry.shard_id), sizeof(entry.shard_id));
    file.read(reinterpret_cast<char *>(&entry.offset), sizeof(entry.offset));
    file.ignore();

    return entry;
}
