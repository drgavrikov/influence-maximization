#ifndef INFLUENCE_MAXIMIZATION_SHARD_INDEX_H
#define INFLUENCE_MAXIMIZATION_SHARD_INDEX_H

struct EdgeShardOffset {
    uint32_t source;
    uint16_t shard_id;
    std::streamoff offset;
};

using ShardIndex = std::vector<EdgeShardOffset>;

#endif //INFLUENCE_MAXIMIZATION_SHARD_INDEX_H
