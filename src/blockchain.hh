#ifndef OB_BLOCKCHAIN_HH
#define OB_BLOCKCHAIN_HH

#include <string>
#include <vector>

class Blockchain
{
public:
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

private:
  Chain chain;
}; // class Blockchain

#endif // OB_BLOCKCHAIN_HH
