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
#include "recorder/RecorderManager.hpp"


int main(int argc, char* argv[]) {
  std::string fileName = "./data/pitch_example_data"; // Binary file name

  MarketDataReader * reader = new MarketDataReader(fileName);
  RecorderManager * recorder_manager = new RecorderManager();



  reader->set_recorder(recorder_manager);

  printf("File size %ul bytes\n", reader->get_file_size());
  reader->read_file_to_recorder();
  printf("Read in %ul of %ul bytes (%d \%)\n", reader->get_file_size()-reader->get_remaining_size(), reader->get_file_size(), (reader->get_file_size()-reader->get_remaining_size()) /reader->get_file_size());

  /* Delete objects */
  delete reader;

  return 0;
}
