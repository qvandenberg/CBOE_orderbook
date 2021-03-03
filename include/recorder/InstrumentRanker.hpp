#ifndef INSTRUMENT_RANKER_HPP
#define INSTRUMENT_RANKER_HPP

/* Internal headers */
#include "recorder/RecorderManager.hpp"


class InstrumentRanker {
private:
  RecorderManager * rm;

public:
  InstrumentRanker(){}
  ~InstrumentRanker(){}

  void set_recorder_manager(RecorderManager*);
  void print_top_stocks(int);
};


#endif
