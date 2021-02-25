#ifndef INSTRUMENT_MAPPING_H
#define INSTRUMENT_MAPPING_H

/* Standard library headers */
#include <string>
#include <stdexcept>

/* External headers */
#include "parallel_hashmap/phmap.h"
#include "parallel_hashmap/btree.h"


/*
Map the LMAX itch definitions for orderBookId to a human-readable string.
e.g. orderBookId 100637 denotes the EUR/USD orderbook.
*/

namespace LMAX {

  std::string orderbook_id_to_instrument(unsigned short int id){
    // static phmap::parallel_flat_hash_set<unsigned short int, std::string>
    static phmap::btree_set<unsigned short int, std::string>
    instrument_map = {
      {100637, "EUR/USD"},
      {100639, "GBP/USD"},
      {100641, "EUR/GBP"},
      {100643, "USD/JPY"},
      {100645, "GBP/JPY"},
      {100647, "EUR/JPY"},
      {100649, "AUD/USD"},
      {100651, "AUD/JPY"},
      {100653, "CHF/USD"},
      {100655, "USD/CHF"},
      {100657, "EUR/CHF"},
      {100659, "GBP/CHF"},
      {100661, "USD/CAD"},
      {100663, "GBP/CAD"},
      {100665, "EUR/CAD"},
      {100667, "EUR/AUD"},
      {100669, "GBP/AUD"},
      {100671, "EUR/CZK"},
      {100673, "GBP/CZK"},
      {100675, "USD/CZK"},
      {100677, "EUR/DKK"},
      {100679, "GBP/DKK"},
      {100681, "USD/DKK"},
      {100683, "EUR/HKD"},
      {100685, "GBP/HKD"},
      {100687, "USD/HKD"},
      {100689, "EUR/HUF"},
      {100691, "GBP/HUF"},
      {100693, "USD/HUF"},
      {100695, "EUR/MXN"},
      {100697, "GBP/MXN"},
      {100699, "USD/MXN"},
      {100701, "EUR/NOK"},
      {100703, "GBP/NOK"},
      {100705, "USD/NOK"},
      {100707, "EUR/NZD"},
      {100709, "GBP/NZD"},
      {100711, "EUR/PLN"},
      {100713, "GBP/PLN"},
      {100715, "USD/PLN"},
      {100717, "EUR/SEK"},
      {100719, "GBP/SEK"},
      {100721, "USD/SEK"},
      {100723, "EUR/SGD"},
      {100725, "GBP/SGD"},
      {100727, "USD/SGD"},
      {100733, "USD/TRY"},
      {100735, "EUR/ZAR"},
      {100737, "GBP/ZAR"},
      {100739, "USD/ZAR"},
      {100741, "NZD/USD"},
      {100743, "AUD/NZD"},
      {100745, "NZD/JPY"},
      {100747, "AUD/CHF"},
      {100789, "AUD/CAD"},
      {100791, "CAD/CHF"},
      {100793, "CAD/JPY"},
      {100795, "NZD/CAD"},
      {100797, "NZD/CHF"},
      {100799, "NZD/SGD"},
      {173534, "EUR/RUB"},
      {177630, "NOK/SEK"},
      {179678, "USD/RUB"},
      {181726, "EUR/TRY"},
      {181727, "GBP/TRY"},
      {191966, "USD/ILS"},
      {212446, "EUR/RON"},
      {212447, "USD/RON"},
      {214494, "USD/CNH"},
      {229854, "USD/THB"},
      {243166, "EUR/CNH"},
      {204254, "XAU/USDm"},
      {204255, "XAG/USDm"},
      {216544, "XAG/AUD"},
      {216545, "XAU/AUD"},
      {216546, "XAU/EUR"},
      {216547, "XAU/USD"},
      {216548, "XAG/USD"}
    };
    std::string instrument = instrument_map[id];
    if (instrument.size() > 0){
      return instrument_map[id];
    }
    else {
      throw std::runtime_error("Financial instrument %d not found in orderBookId list.\n", id);
    }
  }

}


#endif
