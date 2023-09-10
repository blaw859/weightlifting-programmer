#include "excel_exporter.h"

void ExcelExporter::GenerateCellBlock(const ExerciseSession & sesh, int start_row, int start_col, xlnt::worksheet& ws)
{
   int row_offset = 0;
   for (const auto& lift_info : sesh.getLifts()) {
      auto name_cell = ws.cell(xlnt::cell_reference(start_col, start_row + row_offset));
      auto set_cell = ws.cell(xlnt::cell_reference(start_col + 1, start_row + row_offset));
      auto rep_cell = ws.cell(xlnt::cell_reference(start_col + 2, start_row + row_offset));
      auto intensity_cell = ws.cell(xlnt::cell_reference(start_col + 3, start_row + row_offset));
      name_cell.value(lift_info->lift->GetName());
      set_cell.value(lift_info->number_of_sets);
      rep_cell.value(lift_info->number_of_reps);
      intensity_cell.value(lift_info->percent_intensity);
      row_offset++;
   }
}
