#include <ob/parg.hh>
using Parg = OB::Parg;

#include <string>
#include <sstream>
#include <vector>

int program_options(Parg& pg);

int program_options(Parg& pg)
{
  pg.name("blockpp").version("0.1.0 (08.02.2018)");
  pg.description("a blockchain implementation");
  pg.usage("[flags] [options] [--] [arguments]");
  pg.info("Exit Codes", {"0 -> normal", "1 -> error"});
  pg.author("Brett Robinson (octobanana) <octobanana.dev@gmail.com>");

  pg.set("help,h", "print the help output");
  pg.set("version,v", "print the program version");

  // pg.set_pos();
  // pg.set_stdin();

  int status {pg.parse()};
  // uncomment if at least one argument is expected
  // if (status > 0 && pg.get_stdin().empty())
  // {
  //   std::cout << pg.print_help() << "\n";
  //   std::cout << "Error: " << "expected arguments" << "\n";
  //   return -1;
  // }
  if (status < 0)
  {
    std::cout << pg.print_help() << "\n";
    std::cout << "Error: " << pg.error() << "\n";
    return -1;
  }
  if (pg.get<bool>("help"))
  {
    std::cout << pg.print_help();
    return 1;
  }
  if (pg.get<bool>("version"))
  {
    std::cout << pg.print_version();
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[])
{
  Parg pg {argc, argv};
  int pstatus {program_options(pg)};
  if (pstatus > 0)
  {
    return 0;
  }
  else if (pstatus < 0)
  {
    return 1;
  }

  // init here

  return 0;
}
