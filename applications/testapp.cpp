/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <inttypes.h>

/* Internal headers */
#include "market_messages/containers.hpp"
#include "io/binary_reader.hpp"


int main(int argc, char* argv[]) {
  std::string fileName = "./data/binary/itch-daily-2020-11-22_ldprof.itch"; // Binary file name

  BinaryReader * reader = new BinaryReader(fileName);
  printf("File size %ul\n", reader->get_file_size());
  reader->read_file_to_recorder();

  /* Delete objects */
  delete reader;

  return 0;
}
