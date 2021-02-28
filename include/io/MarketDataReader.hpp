#ifndef MARKET_DATA_READER_H
#define MARKET_DATA_READER_H

/* Standard library headers */
#include <string>
#include <fstream>
/* Internal headers */
#include "io/io.hpp"
#include "messages/MessageFactory.hpp"
#include "recorder/RecorderManager.hpp"
// #include "recorder/recorder_interface.hpp"


/* Read market data from file:
- Stream from file with ifstream
- Cast market data messages into internal data formats (contained in messages/containers.hpp)
- Map LMAX codes to currency pairs
- Output internal data objects to Recorder objects
*/

class MarketDataReader {
private:
  MessageFactory* m_factory;

  RecorderManager* recorder_;

  unsigned int bytes_read_;

  std::string market_data_file_path_;

  std::ifstream in_file_;

public:
  MarketDataReader();

  MarketDataReader(std::string file_path);

  ~MarketDataReader();

  void set_recorder(RecorderManager* recorder);

  void read_file_to_recorder();

  unsigned int get_file_size();
  unsigned int get_remaining_size();
};


#endif
