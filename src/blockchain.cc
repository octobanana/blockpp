#include "blockchain.hh"
using Data = Blockchain::Data;
using Block = Blockchain::Block;

#include "crypto.hh"

#include <string>
#include <sstream>
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

std::string Blockchain::hash_block(Block block)
{
  std::stringstream sum;
  sum << block.index << block.timestamp << block.data << block.hash_prev;
  return (Crypto::sha256(sum.str()));
}

Block Blockchain::generate_block(Data data)
{
  Block block;
  block.index = chain.size();
  block.timestamp = std::time(nullptr);
  block.data = data.str;
  block.hash_prev = chain.back().hash;
  block.hash = hash_block(block);
  return block;
}

bool Blockchain::validate_block(Block block, Block block_prev)
{
  bool valid {true};
  if (block.index != block_prev.index + 1)
  {
    valid = false;
  }
  else if (block.hash_prev != block_prev.hash)
  {
    valid = false;
  }
  else if (hash_block(block) != block.hash)
  {
    valid = false;
  }
  return valid;
}
