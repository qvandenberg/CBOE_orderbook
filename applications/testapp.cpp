/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
#include <inttypes.h>

/* Internal headers */
#include "io/MarketDataReader.hpp"


int main(int argc, char* argv[]) {
  std::string fileName = "./data/pitch_example_data"; // Binary file name

  MarketDataReader * reader = new MarketDataReader(fileName);
  printf("File size %ul bytes\n", reader->get_file_size());
  reader->read_file_to_recorder();

  /* Delete objects */
  delete reader;

  printf("Read in %ul of %ul bytes (%d \%)\n", reader->get_file_size()-reader->get_remaining_size(), reader->get_file_size(), (reader->get_file_size()-reader->get_remaining_size()) /reader->get_file_size());

  return 0;
}
