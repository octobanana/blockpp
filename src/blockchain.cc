#include "blockchain.hh"

#include <string>
#include <vector>
#include <ctime>

Blockchain::Blockchain()
{
}

void Blockchain::genesis_block()
{
  Block block;
  block.index = 0;
  block.timestamp = std::time(nullptr);
  block.data = "Genesis Block";
  block.hash_prev = "";
  chain.emplace_back(block);
}
