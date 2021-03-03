/* Standard library headers */
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <utility>
#include <queue>

/* Internal headers */
#include "messages/Message.hpp"
#include "recorder/Order.hpp"
#include "recorder/InstrumentRecorder.hpp"
#include "recorder/RecorderManager.hpp"
#include "recorder/InstrumentRanker.hpp"

void InstrumentRanker::set_recorder_manager(RecorderManager* r_manager){
  rm = r_manager;
}

void InstrumentRanker::print_top_stocks(int num_instruments){
  /* Filter instruments by executed volume */
  //comparator lambda function
  auto sort_comparison = [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
      if (a.second > b.second){
          return false;
      } else if (a.second <= b.second){
        return true;
      }
      else {
        printf("Sorting comparison error\n");
        throw std::invalid_argument( "InstrumentRanker::filter_top_instruments() invalid argument exception" );
      }
    };
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int> >, decltype(sort_comparison)> pq(sort_comparison);

    for (auto& ij : rm->get_instrument_volume_map()) {
        pq.push(ij);
    }
    for (size_t i=0;i!=rm->get_instrument_volume_map().size();i++){
      if (i < num_instruments){
        printf("%s\t%d\n", pq.top().first.c_str(), pq.top().second);
      }
      pq.pop(); // pop entire queue because it lacks a destructor
    }
}
