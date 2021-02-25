#ifndef WRITER_H
#define WRITER_H

/* Standard library headers */
#include <string>
#include <fstream>

/* Internal headers */
#include "io/io.hpp"


/*
Write processed/computed output to text-based files.
Files must be split to maintain a "reasonable" file size.
*/

namespace out {


  class Writer {
  private:
    std::string output_path_prefix;

    std::ifstream out_file;

    unsigned int max_file_size; // in bytes

    unsigned int total_data_size; // in bytes


  public:
    Writer(std::string file_path);

    ~Writer();

    // void set_source(RecorderInterface * recorder);

    void set_max_file_size(unsigned int max_size);

    void set_output_file_prefix(std::string output_file_prefix);

    void receive_output_from_recorder( ); // define exact datatype

  private:
    // write_data();

    // read_binary_into_var(&var, type); // file.read((char*) &(var), sizeof(type))

  };

}

#endif
