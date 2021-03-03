#ifndef MARKET_DATA_READER_H
#define MARKET_DATA_READER_H

/* Standard library headers */
#include <string>
#include <fstream>
/* Internal headers */
#include "messages/MessageFactory.hpp"
#include "recorder/RecorderManager.hpp"


class MarketDataReader {
private:
  MessageFactory* m_factory;
  RecorderManager* recorder_;
  unsigned int bytes_read_;
  std::string market_data_file_path_;
  std::ifstream in_file_;

public:
  MarketDataReader(std::string file_path);
  ~MarketDataReader();

  void set_recorder_manager(RecorderManager* recorder);
  void read_file_to_recorder();

private:
  inline bool file_exists();
  unsigned int get_file_size();
  unsigned int get_remaining_size();
};


#endif
