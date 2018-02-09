#ifndef OB_BLOCKCHAIN_HH
#define OB_BLOCKCHAIN_HH

#include <string>
#include <vector>

class Blockchain
{
public:
  class Data
  {
  public:
    std::string str;
  }; // class Data

  class Block
  {
  public:
    int index;
    std::string timestamp;
    std::string data;
    std::string hash_prev;
    std::string hash;
  }; // class Block

  using Chain = std::vector<Block>;

  Blockchain();

  void genesis_block();
  std::string hash_block(Block block);
  Block generate_block(Data data);
  bool validate_block(Block block, Block block_prev);
  int append_block(Data data);

private:
  Chain chain;
}; // class Blockchain

#endif // OB_BLOCKCHAIN_HH
