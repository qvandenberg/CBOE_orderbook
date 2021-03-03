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
#include "recorder/InstrumentRanker.hpp"


int main(int argc, char* argv[]) {
  std::string fileName = "./data/pitch_example_data";

  MarketDataReader * reader = new MarketDataReader(fileName);
  RecorderManager * recorder_manager = new RecorderManager();
  InstrumentRanker* ranker = new InstrumentRanker();

  /* Set objects dependencies */
  reader->set_recorder_manager(recorder_manager);
  ranker->set_recorder_manager(recorder_manager);

  /* Read data and print top 10 stocks */
  reader->read_file_to_recorder();
  ranker->print_top_stocks(10);

  /* Delete objects */
  delete reader; // also deletes recorder_manager
  delete ranker;

  return 0;
}
