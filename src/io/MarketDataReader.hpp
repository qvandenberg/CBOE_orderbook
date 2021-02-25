#ifndef MARKET_DATA_READER_H
#define MARKET_DATA_READER_H

/* Standard library headers */
#include <string>
#include <fstream>
/* Internal headers */
#include "io/io.hpp"
#include "market_messages/containers.hpp"
#include "recorders/recorder_interface.hpp"


/* Read market data from binary files:
- Stream from file with ifstream
- Cast market data messages into internal data formats (contained in messages/containers.hpp)
- Map LMAX codes to currency pairs
- Output internal data objects to Recorder objects
*/

class MarketDataReader {
private:
  std::string market_data_file_path_;

  std::ifstream in_file_;

  RecorderInterface* recorder_;

  unsigned int bytes_read_;

public:
  MarketDataReader();

  MarketDataReader(std::string file_path);

  ~MarketDataReader();

  unsigned int get_file_size();

  void set_input_file(std::string input_file);

  void set_recorder(RecorderInterface* recorder);

  void read_file_to_recorder();


};


#endif
