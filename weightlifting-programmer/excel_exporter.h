#pragma once
#include <xlnt/xlnt.hpp>
#include "day.h"

class ExcelExporter {
public:
   ExcelExporter(const std::string& file_name) : workbook_(), file_name_(file_name) {}
   void GenerateCellBlock(const std::vector<std::unique_ptr<ExerciseSession>>& sessions, int start_row, int start_col, xlnt::worksheet& ws);
private:
   xlnt::workbook workbook_;
   std::string file_name_;
};
