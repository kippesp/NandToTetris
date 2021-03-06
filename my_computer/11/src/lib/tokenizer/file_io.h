#pragma once

#include <stdio.h>

#include <fstream>

#include "reader.h"

// Simple file reader limited to what is required
class JackInputFile : public Reader {
public:
  using Reader::char_type;

  // sets filename for reading; does not open or checking
  JackInputFile(const std::string& filename);

  virtual ~JackInputFile();

  JackInputFile(Reader&&) = delete;
  JackInputFile& operator=(const JackInputFile&) = delete;
  JackInputFile& operator=(JackInputFile&&) = delete;

  int open();

  // returns one character from the input file without advancing the cursor
  // returns -1 on EOF
  virtual char_type peek() override;

  // returns one character from the input file
  // returns -1 on EOF
  virtual char_type read() override;

private:
  const std::string filename;
  FILE* infile{nullptr};
};
